<?php

use SnailRoute\RouteParser\Std;
use SnailRoute\DataGenerator\GroupCountBased;
use SnailRoute\RouteCollector;


$routeParser = new Std();
$routeData = $routeParser->parse("/user/{id:\d+}[/{name}]");

$dataGenerator = new GroupCountBased();
$routeCollector = new RouteCollector($routeParser, $dataGenerator);

$routeCollector->addRoute('GET', "/user/{id:\d+}[/{name}]", function() {
    echo "user name";
});

$data = $dataGenerator->getData();

var_dump($data);
