const UTIL = require('./util');
module.exports = {
    User: function(id='',name=''){
        this.id=id;         //user id
        this.name=name;       //user nickname  
    },
    Chat: function(id='',name='',masterID='',topic=''){
        this.id=id;         //chat방 id
        this.name=name;       //chat방 이름
        this.masterID=masterID;   //chat방 소유주 아이디
        this.topic=topic;      //chat방 kafka topic
    },
    Message: function(sender='',message='',datetime=UTIL.getDate(),){
        this.sender=sender;     //발신인
        this.datetime=datetime;   //발신 시간(yyyy-mm-dd hh:mm:ss)
        this.message=message;    //발신 내용
    },
    Response: function(status,message){
        this.status = status;
        this.message = message;
    }
}