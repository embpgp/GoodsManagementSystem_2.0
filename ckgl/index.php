<?php 
header("content-type:text/html;charset=utf-8");

$db = new SQLite3('C:\Users\PGP\Desktop\ex05_Drug_Sale_Mangage_System\build-DrugSaleManageSystem-desktop-Debug\debug\GoodsManage.db');

@$type = $_GET['type'];
if ($type == 'inventory') {
	$results = $db->query('SELECT * FROM tbl_goods,tbl_inventory where tbl_goods.id=tbl_inventory.gid');
	while ($row = $results->fetchArray(SQLITE3_ASSOC)) {
		//var_dump($row);
		echo "<tr><td>$row[id]</td><td>$row[cardid]</td><td>$row[name]</td><td>$row[price]</td><td>$row[count]</td></tr>";
    }
}else if ($type == 'record') {
	if (@$_GET['value'] =='' || $_GET['value'] == 0) {
		$results = $db->query('SELECT * FROM tbl_record,tbl_goods where tbl_record.gid=tbl_goods.id');
		while ($row = $results->fetchArray(SQLITE3_ASSOC)) {
		//var_dump($row);
		$row['type'] = $row['type'] == 1 ? '入库':'出库';
		echo "<tr><td>$row[id]</td><td>$row[name]</td><td>$row[price]</td><td>$row[count]</td><td>$row[type]</td><td>$row[date]</td></tr>";
    	}
	}else{
		$qstring = "SELECT * FROM tbl_record,tbl_goods where tbl_record.gid=tbl_goods.id and tbl_goods.catid=$_GET[value]";
		$results = $db->query($qstring);
		while ($row = $results->fetchArray(SQLITE3_ASSOC)) {
		//var_dump($row);
		$row['type'] = $row['type'] == 1 ? '入库':'出库';
		echo "<tr><td>$row[id]</td><td>$row[name]</td><td>$row[price]</td><td>$row[count]</td><td>$row[type]</td><td>$row[date]</td></tr>";
		}
	}
}else if ($type == 'cate') {
	$results = $db->query('SELECT * FROM tbl_categories');
	echo "<option value='0'>全部</option>";
	while ($row = $results->fetchArray(SQLITE3_ASSOC)) {
		//var_dump($row);
		echo "<option value='$row[id]'>$row[name]</option>";
    }
}
?>