#include "UHF900MPackage.h"

UHF900MPackage::UHF900MPackage()
    : _valid(false)
    , _isNormalPackage(true)
{
}

UHF900MPackage::UHF900MPackage(const QByteArray &rawPkg)
{
    load(rawPkg);
}

UHF900MPackage::UHF900MPackage(PackageType type, CommandType cmd, quint8 devNum, const QByteArray &data)
{
    create(type, cmd, devNum, data);
}

quint8 UHF900MPackage::calcCheckSum(const quint8 *p, int len)
{
    quint8 chksum = 0;
    while(len-- > 0)
    {
        chksum += *p++;
    }
    chksum = (~chksum) + 1;
    return chksum;
}

quint8 UHF900MPackage::calcCheckSum(const QByteArray &d)
{
    return calcCheckSum((const quint8 *)d.constData(), d.size());
}

quint8 UHF900MPackage::calcCheckSum(void)
{
    _chksum = 0;
    _chksum += _pkgType;
    _chksum += _length;
    _chksum += _code;
    _chksum += _devNumber;
    const quint8 *p = (const quint8 *)_data.constData();
    int len = _data.size();
    while(len-- > 0)
        _chksum += *p++;
    _chksum = (~_chksum) + 1;
    return _chksum;
}

bool UHF900MPackage::load(const QByteArray &rawPkg)
{
    _valid = false;
    do {
        // do some basic test
        // pkgType+len+code+devNum+chkSum
        if(rawPkg.size() < 5)
            break;
        if(rawPkg.at(0) == 0x00)
        {
            _isNormalPackage = false;
            if(rawPkg.size() != 17)
                break;
            _chksum = rawPkg.right(2).at(0);
            if(_chksum != calcCheckSum((quint8 *)rawPkg.constData(), rawPkg.size() - 2))
                break;

            const quint8 *p = (const quint8 *)rawPkg.constData();
            _pkgType = *p++;
            _length = 0;
            _code = 0xFF;
            _devNumber = 0;
            _data.clear();
            _data.append(rawPkg.mid(2, 13));
            _valid = true;
        }
        else
        {
            _isNormalPackage = true;
            if((quint8)rawPkg.right(1).at(0) != calcCheckSum((quint8 *)rawPkg.constData(), rawPkg.size() - 1))
                break;

            const quint8 *p = (const quint8 *)rawPkg.constData();
            int len = rawPkg.size();
            if((*p != CommandPkg) && (*p != StatusPkg) && (*p != InformationPkg))
                break;
            _pkgType = *p++;
            len--;
            _length = *p++;
            len--;
            if(len != _length)
                break;
            _code = *p++;
            len--;
            _devNumber = *p++;
            len--;
            _data.clear();
            if(len > 1)
                _data.append((char *)p, len - 1);
            p += (len - 1);
            _chksum = *p;
            _valid = true;
        }
    } while(0);
    return _valid;
}

bool UHF900MPackage::create(PackageType type, CommandType cmd, quint8 devNum, const QByteArray &data)
{
    _valid = true;
    _pkgType = type;
    _length = 3 + data.size();
    _code = cmd;
    _devNumber = devNum;
    _data = data;
    calcCheckSum();
    _isNormalPackage = true;
    return true;
}

QByteArray UHF900MPackage::toRawPackage() const
{
    if(!_valid)
        return QByteArray();
    QByteArray ret;
    if(_isNormalPackage)
    {
        ret.append(_pkgType);
        ret.append(_length);
        ret.append(_code);
        ret.append(_devNumber);
        ret.append(_data);
        ret.append(_chksum);
    }
    else
    {
        ret.append(_pkgType);
        ret.append((char)0x00);
        ret.append(_data);
        ret.append(_chksum);
        ret.append(0xFF);
    }
    return ret;
}
