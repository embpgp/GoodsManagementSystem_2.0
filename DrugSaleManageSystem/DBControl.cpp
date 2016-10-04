#include "DBControl.h"
#include <QDebug>
#include <stdio.h>
#include <QMessageBox>
#include <QDebug>
/*****************************************************************/
/* DBControl class                                               */
/*****************************************************************/
QSqlDatabase *DBControl::_mainDB = NULL;
DBControl::DBControl()
    : q(NULL)
{}
DBControl::~DBControl()
{
    if(q)
    {
        delete q;
        q = NULL;    //不能成为野指针
    }
}

bool DBControl::Create()
{
    if(_mainDB != NULL)
        return true;
    _mainDB = new QSqlDatabase;
    *_mainDB = QSqlDatabase::addDatabase("QSQLITE", "GoodsManage");
    _mainDB->setDatabaseName("GoodsManage.db");
    if(!_mainDB->open())
    {
        delete _mainDB;
        _mainDB = NULL;
        QSqlDatabase::removeDatabase("GoodsManage");
        return false;
    }
    checkDatabase();
    return true;
}

void DBControl::Destroy()
{
    if(_mainDB != NULL)
    {
        _mainDB->close();
        delete _mainDB;
        _mainDB = NULL;
    }
    QSqlDatabase::removeDatabase("GoodsManage");
}

bool DBControl::checkTable(const QString &tblName)
{
    if(_mainDB == NULL)
        return false;
    QSqlQuery q(*_mainDB);
    QString sql = QString("SELECT COUNT(*)  as CNT FROM sqlite_master where type='table' and name= '%1'").arg(tblName);
    if(!q.exec(sql))
        return false;
    if(!q.first())
    {
        q.finish();
        return false;
    }
    int count = q.value(0).toInt();
    q.finish();
    return (count > 0);
}

void DBControl::removeTable(const QString &tblName)
{
    if(_mainDB == NULL)
        return;
    QSqlQuery q(*_mainDB);
    QString sql = QString("DROP TABLE [%1]").arg(tblName);
    q.exec(sql);
    q.finish();
}

bool DBControl::createTable(const QString &tblName, const QStringList &fieldList)   //直接建立表的所有属性
{
    if(_mainDB == NULL)
    {

        return false;
    }
    if(fieldList.count() <= 0)
    {

         return false;
    }
    if(checkTable(tblName))
        return true;
    QSqlQuery q(*_mainDB);
    QString sql = QString("CREATE TABLE [%1] (").arg(tblName);
    QStringList::const_iterator i;
    for(i = fieldList.constBegin(); i != fieldList.constEnd(); ++i)
    {
        sql += (*i);
        sql += ",";
    }
    if(sql.at(sql.length() - 1) == ',')
        sql = sql.left(sql.length() - 1);
    else
    {

        return false;
    }
    sql += ")";
    bool ret = q.exec(sql);

    q.finish();
    return ret;
}

void DBControl::checkDatabase()
{
    if(_mainDB == NULL)
        return;
    if(!checkTable("tbl_goods"))
    {
        createTable("tbl_goods", QStringList()                         //物品表
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"   //物品id 主键 自增
                    <<"[cardid] VARCHAR(12)  UNIQUE NOT NULL"             //标签号
                    <<"[name]   VARCHAR(32) NOT NULL"                    //物品的名字
                    <<"[price] FLOAT NOT NULL"                           // 价格
                    <<"[catid] INTEGER NOT NULL"           //类别id（外键）
                    );
    }


    if(!checkTable("tbl_categories"))   //类别表
    {
        createTable("tbl_categories",QStringList()
                    <<"[id] INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"   //类别 id 主键 自增                        
                    <<"[name] VARCHAR(20) NOT NULL"     //类别名字
                    );

        DBCategories::Init_Categories();

    }


    if(!checkTable("tbl_record"))                      //记录表
    {
        createTable("tbl_record", QStringList()\
                    <<"[id] INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT"   //记录id  主键 自增
                    <<"[date] TIMESTAMP DEFAULT(datetime('now','localtime')) NOT NULL"   //记录时间
                    <<"[count] INTEGER NOT NULL"                           //出入库的货物量
                    <<"[type] INTEGER NOT NULL DEFAULT 1"                   //出入库类型 0 出库 1 入库
                    <<"[gid] INTERGER NOT NULL "   //物品外键
                    );
    }




    if(!checkTable("tbl_inventory"))                                            //库存表
    {
        createTable("tbl_inventory",QStringList()                                 //
                    <<"[id] INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"    //库存id  主键  自增
                    <<"[count] INTEGER NOT NULL"                             //库存数量
                    <<"[gid] INTEGER NOT NULL"                            //物品id
                    );

    }
}

/*****************************************************************/
/* DBDrugInfo class                                              */
/*****************************************************************/
DBDrugInfo::DBDrugInfo(const QString &cardid)           //根据标签卡号id查找
{
    QString sql = QString("SELECT [id],[cardid],[name],[price],[catid] FROM [tbl_goods]");
    if(!cardid.isEmpty())
        sql += QString(" WHERE [cardid] = '%1'").arg(cardid);
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    else
        q->first();
}
DBDrugInfo::DBDrugInfo(int catid)
{
    QString sql = QString("SELECT [id],[cardid],[name],[price],[catid] FROM [tbl_goods] WHERE [catid] = %1").arg(catid);

    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    else
        q->first();
}

bool DBDrugInfo::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBDrugInfo::next()
{
    if(q == NULL)
        return false;
    return q->next();
}

int DBDrugInfo::id() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(0).toInt();
}

QString DBDrugInfo::cardid() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(1).toString();
}

QString DBDrugInfo::name() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(2).toString();
}

float DBDrugInfo::price() const
{
    if(q == NULL)
        return 0.0;
    if(!q->isActive())
        return 0.0;
    if(!q->isValid())
        return 0.0;
    return q->value(3).toFloat();
}
int DBDrugInfo::catid() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(4).toInt();

}




QString DBDrugInfo::findName(const QString &cardid)
{
    QString sql = QString("SELECT [name] FROM [tbl_goods] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}



float DBDrugInfo::findPrice(const QString &cardid)
{
    QString sql = QString("SELECT [price] FROM [tbl_goods] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0.0;
    if(!q.first())
        return 0.0;
    float ret = q.value(0).toFloat();
    q.finish();
    return ret;
}



int DBDrugInfo::findCatid(const QString &cardid)
{
    QString sql = QString("SELECT [catid] FROM [tbl_goods] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0;
    if(!q.first())
        return 0;
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}

int DBDrugInfo::findId(const QString &cardid)
{
    QString sql = QString("SELECT [id] FROM [tbl_goods] WHERE [cardid] = '%1'").arg(cardid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0;
    if(!q.first())
        return 0;
    int ret = q.value(0).toInt();
    q.finish();
    return ret;

}

float DBDrugInfo::findPrice(const int gid)
{
    QString sql = QString("SELECT [price] FROM [tbl_goods] WHERE [id] = %1").arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0.0;
    if(!q.first())
        return 0.0;
    float ret = q.value(0).toFloat();
    q.finish();
    return ret;
}

QString DBDrugInfo::findName(const int gid)
{
    QString sql = QString("SELECT [name] FROM [tbl_goods] WHERE [id] = %1").arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return QString();
    if(!q.first())
        return QString();
    QString ret = q.value(0).toString();
    q.finish();
    return ret;
}

//重点中的重点
//参数  1、卡片的标签id   2、物品的名字  3、物品所存放的区域名字（类别名字）  4、价格 5、数量
void DBDrugInfo::buyIn(const QString &cardid, const QString &goods_name,const QString &cate_name, float price, int count)
{
    if(findName(cardid).isEmpty())
    {
        if(!DBCategories::findId(cate_name))
        {

            DBCategories::addCategories(cate_name);   //增加类别分区
        }

        int catid = DBCategories::findId(cate_name); //获得分区的主键，准备插入物品表中
   //     qDebug()<<catid;
        QString sql = QString("INSERT INTO [tbl_goods] ([cardid], [name], [price],[catid]) VALUES ('%1', '%2', %3, %4)")
                      .arg(cardid).arg(goods_name).arg(price).arg(catid);
        QSqlQuery q(*_mainDB);
        q.exec(sql);
        q.finish();


        int gid = findId(cardid);

        DBInventory::ModifyInventory(count, gid);  //更新库存表

    }
    else                        //以后已经存在物品的情况
    {

        int gid = findId(cardid);
        int oldcount = DBInventory::findCount(gid);
        qDebug()<<QObject::tr("旧的库存")<<oldcount;
        oldcount += count;

        QString sql = QString("UPDATE [tbl_inventory] SET [count] = %1 WHERE [gid] = %2")
                      .arg(oldcount).arg(gid);
        QSqlQuery q(*_mainDB);
        q.exec(sql);
        q.finish();
    }


    DBRecord::addBuyInRecord(cardid, count);    //同时更新记录表
}

void DBDrugInfo::saleOut(const QString &cardid, int count)
{
    if(findName(cardid).isEmpty())
        return;

    int gid = findId(cardid);
    int oldcount = DBInventory::findCount(gid);
    oldcount -= count;
    if(oldcount < 0)
    {


        QMessageBox::warning(NULL,QObject::tr("警告"),QObject::tr("商品'%1'库存不够，请先增加库存").arg(findName(cardid)),QMessageBox::Abort);
        return;

    }
    else
    {          //先更新库存表
        QString sql = QString("UPDATE [tbl_inventory] SET [count] = %1 WHERE [gid] = '%2'")
                      .arg(oldcount).arg(gid);
        QSqlQuery q(*_mainDB);
        q.exec(sql);
        q.finish();
    }
    if(oldcount == 0)
    {
        QMessageBox::warning(NULL,QObject::tr("警告"),QObject::tr("商品'%1'库存为0，请及时增加库存").arg(findName(cardid)),QMessageBox::Abort);
    }
         //再更新记录表
    DBRecord::addSaleOutRecord(cardid, count);
}



/*****************************************************************/
/* DBRecord class                                                */
/*****************************************************************/
DBRecord::DBRecord()
{
    QString sql = QString("SELECT [id], [date],[count], [type], [gid] FROM [tbl_record]");
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    q->first();
}

DBRecord::DBRecord(const QString &cate_name)    //这里必须使用联合查询，不能一步一步依靠主键查
{
    int cate_id = DBCategories::findId(cate_name);

    QString sql = QString("select tbl_record.id, [date],[count], [type], [gid] from  tbl_goods, tbl_record where tbl_goods.id = tbl_record.gid and tbl_goods.catid = %1;").arg(cate_id);
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    q->first();

}

bool DBRecord::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBRecord::next()
{
    if(q == NULL)
        return false;
    return q->next();
}

int DBRecord::id() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(0).toInt();
}

QDateTime DBRecord::date() const
{
    if(q == NULL)
        return QDateTime();
    if(!q->isActive())                               //格林威治时间+8小时就等于东8区的时间
        return QDateTime();
    if(!q->isValid())
        return QDateTime();


    return q->value(1).toDateTime();
}


int DBRecord::count() const
{
    if(q == NULL)
        return 0;
    if(!q->isActive())
        return 0;
    if(!q->isValid())
        return 0;
    return q->value(2).toInt();
}

int DBRecord::type() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(3).toInt();
}


int DBRecord::gid() const    //物品id
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(4).toInt();
}


//重点中的重点
void DBRecord::addBuyInRecord(const QString &cardid,int count)
{
    int gid = DBDrugInfo::findId(cardid);
    QString sql = QString(
                "INSERT INTO [tbl_record] ([count], [type], [gid]) VALUES (%1, 1,%2)"
            ).arg(count).arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

void DBRecord::addSaleOutRecord(const QString &cardid,int count)
{
    int gid = DBDrugInfo::findId(cardid);
    QString sql = QString(
                "INSERT INTO [tbl_record] ([count], [type], [gid]) VALUES (%1, 0,%2)"
            ).arg(count).arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}

/*****************************************************************/
/* DBCategories class   类别表类                                                */
/*****************************************************************/


DBCategories::DBCategories()
{
    QString sql = QString("SELECT [id], [name] FROM [tbl_categories]");
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    q->first();
}

bool DBCategories::first()
{
    if(q == NULL)
        return false;
    return q->first();
}

bool DBCategories::next()
{
    if(q == NULL)
        return false;
    return q->next();
}

int DBCategories::id() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(0).toInt();
}

QString DBCategories::name() const
{
    if(q == NULL)
        return QString();
    if(!q->isActive())
        return QString();
    if(!q->isValid())
        return QString();
    return q->value(2).toString();
}


int DBCategories::findId(const QString &cate_name)
{
    QString sql = QString("SELECT [id] FROM [tbl_categories] WHERE [name] = '%1'").arg(cate_name);

    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
    {
        return 0;
    }
    if(!q.first())
    {   
        return 0;
    }
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}


int DBCategories::CountCate(void)
{
    QString sql = QString("SELECT COUNT(*)  FROM [tbl_categories] ");

    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
    {
        return 0;
    }
    if(!q.first())
    {
        return 0;
    }
    int ret = q.value(0).toInt();
    q.finish();
    return ret;

}

void DBCategories::Init_Categories()
{
    QString sql = QString("INSERT INTO [tbl_categories] ( [name]) VALUES ('%1')").arg(QObject::tr("潮湿区"));
    QSqlQuery q(*_mainDB);
    q.exec(sql);

    sql = QString("INSERT INTO [tbl_categories] ( [name]) VALUES ('%1')").arg(QObject::tr("危险区"));
    q.exec(sql);

    sql = QString("INSERT INTO [tbl_categories] ( [name]) VALUES ('%1')").arg(QObject::tr("干燥区"));
    q.exec(sql);
    q.finish();

}

QString DBCategories::findName(int cateid)
{
    QString sql = QString("SELECT [name] FROM [tbl_categories] WHERE [id] = %1").arg(cateid);

    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
    {
        return 0;
    }
    if(!q.first())
    {
        return 0;
    }
    QString ret = q.value(0).toString();
    qDebug()<<"ret cate_name:"<<ret;
    q.finish();
    return ret;

}

void DBCategories::addCategories(const QString &cate_name)
{
    QString sql = QString(
                "INSERT INTO [tbl_categories] ( [name]) VALUES ('%1')"
            ).arg(cate_name);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();

}


/*****************************************************************/
/* DBInventory class   库存表类                                                */
/*****************************************************************/


DBInventory::DBInventory()
{
    QString sql = QString("SELECT [id], [count], [gid] FROM [tbl_inventory]");
    q = new QSqlQuery(*_mainDB);
    q->exec(sql);
    if(!q->isActive())
    {
        delete q;
        q = NULL;
    }
    q->first();
}

bool DBInventory::first()
{
    if(q == NULL)
        return false;
    return q->first();
}


bool DBInventory::next()
{
    if(q == NULL)
        return false;
    return q->next();
}

int DBInventory::id() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(0).toInt();
}

int DBInventory::count() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(1).toInt();
}


int DBInventory::gid() const
{
    if(q == NULL)
        return -1;
    if(!q->isActive())
        return -1;
    if(!q->isValid())
        return -1;
    return q->value(2).toInt();
}


int DBInventory::findCount(int gid)
{
    QString sql = QString("SELECT [count] FROM [tbl_inventory] WHERE [gid] = %1").arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0;
    if(!q.first())
        return 0;
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}

int DBInventory::findId(int gid)
{
    QString sql = QString("SELECT [id] FROM [tbl_inventory] WHERE [gid] = %1").arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    if(!q.isActive())
        return 0;
    if(!q.first())
        return 0;
    int ret = q.value(0).toInt();
    q.finish();
    return ret;
}

void DBInventory::ModifyInventory(int count, int gid)
{
    QString sql = QString(
                "INSERT INTO [tbl_inventory] ([count], [gid]) VALUES (%1, %2)"
            ).arg(count).arg(gid);
    QSqlQuery q(*_mainDB);
    q.exec(sql);
    q.finish();
}
