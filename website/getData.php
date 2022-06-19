<?php
$strJsonFileContents = file_get_contents("../json/data.json");

$array = json_decode($strJsonFileContents, true);

#$time = $array["dis60"][0]["time"];
#$name = $array["dis60"][0]["name"];
#echo $time,$name;
#$time2 = $array["data"]["60"][1]["time"];

foreach ($array['dis80'] as $field) {
    echo $field["name"].' ';
    echo number_format((float)$field['time'], 2, '.', '')."<br>";
}

?>


