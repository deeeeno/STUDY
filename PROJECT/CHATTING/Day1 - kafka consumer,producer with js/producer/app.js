const express = require('express');
const producer = require('./producer');
const app = express();
app.use(express.json())
app.use(express.urlencoded({extended:false}));
const port = 3000;

console.log(producer);

app.post('/message',(req,res)=>{
    console.log(req.body.msg);
    producer.send([{'topic':'chat', 'messages':req.body.msg}],(err,data)=>{
        if(err != null){
            res.send({'status':'error','message':err});
        }else{
            res.send({'status':'success','message':data});
        }
    })
})

app.get('/', (req, res) => {
    res.send('Hello World!')
})

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
})