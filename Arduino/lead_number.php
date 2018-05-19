<?php
	$connect = mysql_connect("ybj.cghzrrdlqojc.ap-northeast-2.rds.amazonaws.com", "woojae", "YBJ11111");
	mysql_select_db("free_time", $connect);
	error_reproting(E_ALL);
	$result = mysql_query("SELECT waiting_num, calling_start, calling_end FROM number");
	$row = mysql_fetch_row($result);
?>