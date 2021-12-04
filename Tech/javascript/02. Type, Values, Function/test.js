
var x = 1;

function print() {
    console.log(x); // 1
}

function test() {
    var x = 999;
    print();
}

test();