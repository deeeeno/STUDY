const express = require('express')
const app = express()
app.use(express.json())
app.use(express.urlencoded({extended:false}));
const port = 3000
let member_list = {};

//////////////////////
/// GET  /members/{name}   -> 이름이 name인 멤버를 반환
/// POST /members/{name}   -> 이름이 name인 멤버를 생성
///      body엔 age,phone정보가 들어있다.
/// PUT  /members/{name}   -> 이름이 name인 멤버를 수정
///      body엔 age,phone정보가 들어있다.
/// DELETE /members/{name} -> 이름이 name인 멤버를 삭제

app.get('/members/:name', (req,res)=>{
    const member = member_list[req.params.name];
    console.log('MEMBER GET ACTION -> GET MEMBER');
    if(member == undefined)
        res.send({'message':'There is no Member name['+req.params.name+']'})
    else{
      var ret = {'message':'success'};
      ret['data'] = member;
      res.send(ret);
    }    
});

app.post('/members/:name',(req,res)=>{
    const member_info = req.body;
    const member_age = member_info.age == undefined ? '' : member_info.age;
    const member_phone = member_info.phone == undefined ? '' : member_info.phone;
    console.log('MEMBER POST ACTION -> ADD MEMBER');
    member_list[req.params.name] = {
        'name' : req.params.name,
        'age' : member_age,
        'phone' : member_phone
    };
    console.log(member_list[req.params.name]);
    var ret = {};
    ret['message'] = 'success';
    ret['data'] = member_list[req.params.name];
    res.send(ret);
});

app.put('/members/:name',(req,res)=>{
  const member_info = req.body;
  const member_age = member_info.age == undefined ? '' : member_info.age;
  const member_phone = member_info.phone == undefined ? '' : member_info.phone;
  console.log('MEMBER PUT ACTION -> UPDATE MEMBER');
  if(member_list[req.params.name] == undefined){
    res.send({'message':'There is no Member name['+req.params.name+']'})
  }
  if(member_age != undefined){
    member_list[req.params.name]['age'] = member_age;
  }
  if(member_phone != undefined){
    member_list[req.params.name]['phone'] = member_phone;
  }
  
  console.log(member_list[req.params.name]);
  var ret = {};
  ret['status'] = 'success';
  ret['data'] = member_list[req.params.name];
  res.send(ret);
});

app.delete('/members/:name', (req,res)=>{
  const member = member_list[req.params.name];
  console.log('MEMBER DELETE ACTION -> DELETE MEMBER');
  if(member == undefined)
      res.send({'message':'There is no Member name['+req.params.name+']'})
  else{
    delete member_list[req.params.name];
    var ret = {'message':'success'};
    res.send(ret);
  }    
});

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})