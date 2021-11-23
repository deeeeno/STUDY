const { resolve } = require("../webpack.config");

var func1 = (a,b)=>{
    console.log(a);
    console.log(b);
}

function func2(a=1,b=2){
    console.log(a);
    console.log(b);
}

function promiseFunc(a){
    new Promise(()=>{
        if(a==1)
            resolve('good');
        else
            reject('fail');
    }).then((res)=>{
        console.log(res);
    }).catch((rej)=>{
        console.log('error');
    })
}