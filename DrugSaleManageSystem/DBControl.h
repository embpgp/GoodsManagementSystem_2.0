#ifndef DBCONTROL_H
#define DBCONTROL_H
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVariant>

class DBControl
{
public:
    DBControl();
    virtual ~DBControl();

    static bool Create();       //建立数据库
    static void Destroy();     //删除数据库

protected:
    static QSqlDatabase *_mainDB;
    static bool checkTable(const QString &tblName);     //检测表是否存在
    static bool createTable(const QString &tblName, const QStringList &fieldList);  //建立表
    static void removeTable(const QString &tblName);                //移除表，当数量为0时候
    static void checkDatabase();                           //看所有的表是否存在，少一个就新建一个

protected:
    QSqlQuery *q;                       //数据库操作的指针
};

class DBDrugInfo : public DBControl
{
public:
    DBDrugInfo(const QString &cardid = "");
    DBDrugInfo(int catid);
    bool first();
    bool next();
    int id() const;               //自增的id
    QString cardid() const;      //卡的cardid号，12字节长度
    QString name() const;
    float price() const;
    int catid() const;    //类别表id   外键

     //所有的static函数几乎都是通过SQL语句来取得数据库中相应的数据
    static QString findName(const QString &cardid);   //根据卡的标签号来寻找其他物品属性
    static float findPrice(const QString &cardid);
    static int findCatid(const QString &cardid);       //类别id
    static int findId(const QString &cardid);          //物品id
    static QString findName(const int gid);
    static float findPrice(const int gid);

    static void buyIn(const QString &cardid, const QString &goods_name,const QString &cate_name, float price, int count);   //入库表单
    static void saleOut(const QString &cardid, int count);  //出库表单
};


//出入库记录表
class DBRecord : public DBControl
{
public:
    DBRecord();
    DBRecord(const QString &cate_name);

    bool first();
    bool next();
    int id() const;
    QDateTime date() const;
    int count() const;
    int type() const;
    int gid() const;     //物品id号，


    static void addBuyInRecord(const QString &cardid,int count);
    static void addSaleOutRecord(const QString &cardid, int count);
};



//类别表
class DBCategories:public DBControl
{
public:
    DBCategories();

    bool first();
    bool next();
    int id()const;
    QString name() const;

    static void Init_Categories(void);
    static int CountCate(void);
    static int findId(const QString & cate_name);
    static QString findName(int cateid);
    static void addCategories(const QString & cate_name );

};

//库存表

class DBInventory:public DBControl
{
public:
    DBInventory();

    bool first();
    bool next();

    int id() const;
    int count() const;
    int gid() const;

    static int findCount(int gid);            //根据 物品的gid来找其他属性
    static int findId(int gid);

    static void ModifyInventory(int count,int gid);

};
#endif // DBCONTROL_H
