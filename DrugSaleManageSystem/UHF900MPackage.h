#ifndef UHF900MPACKAGE_H
#define UHF900MPACKAGE_H
#include <QByteArray>
#include <QString>

class UHF900MPackage
{
    bool _valid;
    bool _isNormalPackage;
    quint8 _pkgType;
    quint8 _length;
    quint8 _code;
    quint8 _devNumber;
    QByteArray _data;
    quint8 _chksum;

public:
    enum PackageType {
        EpcIdPkg = 0x00,
        CommandPkg = 0xA0,          // Host --> Device
        // pkgType, length, cmd, devNumber, cmdData1, ..., cmdDataN, chksum
        StatusPkg = 0xE4,           // Device --> Host
        // pkgType, length(4), cmd, devNumber, status, chksum
        InformationPkg = 0xE0,      // Device --> Host
        // pkgType, length, respCode, devNumber, respData1, ..., respDataN, chksum
    };
    enum ErrorCode { NoneErr = 0x00, CrcErr = 0x02, CmdErr = 0x10, OthErr = 0x01 };
    // Command List for CommandPkg
    enum CommandType {
        IdentifyEPC = 0x82,         // none cmdData, for Single Scan
        ReadEPC = 0x80,             // memBank, addr, length
        WriteEPC = 0x81,            // writeMode(00), memBank, addr, length(01), data0, data1
        GetVersion = 0x6A,          // none cmdData
        ResetDevice = 0x65,         // none cmdData
        StopIdentifyEPC = 0xA8,     // none cmdData
        ReIdentifyEPC = 0xFC,       // none cmdData, for Multi Scan mode only
        ReGetEPC = 0xFF,
        ReadSetting = 0x61,
        WriteSetting = 0x60
    };
    UHF900MPackage();
    // for recved package
    UHF900MPackage(const QByteArray &rawPkg);
    // for send package
    UHF900MPackage(PackageType type, CommandType cmd, quint8 devNum, const QByteArray &data = QByteArray());

    // Common operation
    bool isValid() const {
        return _valid;
    }
    bool isNormalPackage() const {
        return _isNormalPackage;
    }
    bool isCommand() const {
        if(!isValid())
            return false;
        return (_pkgType == CommandPkg);
    }
    bool isStatus() const {
        if(!isValid())
            return false;
        return (_pkgType == StatusPkg);
    }
    bool isInformation() const {
        if(!isValid())
            return false;
        return (_pkgType == InformationPkg);
    }
    quint8 packageType() const {
        return _pkgType;
    }
    quint8 length() const {
        return _length;
    }
    quint8 command() const {
        return _code;
    }
    quint8 devNumber() const {
        return _devNumber;
    }
    QByteArray data() const {
        return _data;
    }
    quint8 checkSum() const {
        return _chksum;
    }
    QByteArray toRawPackage() const;

private:
    static quint8 calcCheckSum(const quint8 *p, int len);
    static quint8 calcCheckSum(const QByteArray &d);
    quint8 calcCheckSum(void);
    bool load(const QByteArray &rawPkg);
    bool create(PackageType type, CommandType cmd, quint8 devNum, const QByteArray &data = QByteArray());
};

#endif // UHF900MPACKAGE_H
