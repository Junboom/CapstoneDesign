<?php
  $servername = "localhost";
  $username = "abc_user";
  $password = "abc_1234";
  $dbname = "abc_sens";
  date_default_timezone_set('Asia/Seoul');
  $now = new DateTime();
  parse_str( html_entity_decode( $_SERVER['QUERY_STRING']) , $out);
  if ( array_key_exists( 'temperature', $out ) ) {
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }
    $datenow = $now->format("Y-m-d H:i:s");
    $temp  = $out['temperature'];
    $humid = $out['humidity'];
    $sql = "INSERT INTO sens_table (sensDate , temperature, humidity) VALUES ('$datenow' , $temp, $humid)";
    if ($conn->query($sql) === TRUE) {
      echo "Sensed data saved.";
    } else {
      echo "Error: " . $sql . "<br>" . $conn->error;
    }
    $conn->close();
  }
?>
