<?php
/*
1. get all the data from selected user!
2. find last time& best time
*/
function GetDataUser($name){
    $data = array();

    $data[0]=array();
    $data[0]['name'] = " ";
    $data[0]['distance'] = " ";
    $data[0]['estafette'] = " ";
    $data[0]['time'] = " ";
        
    $file = fopen("/home/timing/RPI/bin/data.txt", "r");
    while (!feof($file)) {
        $var =  fgets($file);
        $var = rtrim($var, "\n");
        $members[] = $var;
    }
    $j = 0;
    for($i=1;$i<sizeof($members);$i=$i+6){
        if($i > sizeof($members)){
            break;
        }else if(strcmp($members[$i],$name) == 0){
    
                $data[$j]['name'] = rtrim($members[$i],"\n");
                $data[$j]['distance'] = rtrim($members[$i+1],"\n");
                $data[$j]['estafette'] = rtrim($members[$i+2],"\n");
                $data[$j]['time'] = rtrim($members[$i+3],"\n");
                $j = $j + 1;
        }
    }
    //print_r($data);
    return $data;
}
function GetBestTime($data, $distance){
    $best = NULL;
    for($i=0;$i< sizeof($data);$i =$i+1){
        if(strcmp($distance,$data[$i]['distance'])==0){
            if(floatval($data[$i]['time']) < $best || $best == 0.0){  
                $best = floatval($data[$i]['time']);
            }
            
        }
    }
    if($best == NULL){
        return "not set";
    }else{
        return $best;
    }
}
function GetCurrentTime(){
    return exec("cat /home/timing/RPI/bin/curTime.txt");
}

?>


