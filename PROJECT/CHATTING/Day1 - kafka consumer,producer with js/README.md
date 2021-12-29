# PROJECT Day 1 - Producer,Consumer in nodejs
프로젝트 1차 단계는 nodejs에서 카프카를 사용할 수 있도록 하는 것이다. nodejs 에서 사용할 수 있는 라이브러리로 kafka-node라는 것이 있다.   
해당 라이브러리에 대한 github는 밑 참조 항목의 url이다.    
카프카에 대한 정리는 따로 할 예정이다. 여기선 카프카 서버에 접근하고 메세지를 보내고 받는 것만 확인해보자.

## Connection
```
const KAFKA_IP = 'localhost:9092';
const kafka = require('kafka-node');
const client = new kafka.KafkaClient({kafkaHost : KAFKA_IP});
//local에서 테스트를 한다면 아래로 해도 무방
//const client = new kafka.KafkaClient;
/*
KafkaClient -> 카프카 브로커에 직접 연결하는 오브젝트.
주요 파라미터
kafkaHost : 연결할 카프카 호스트 여러개면 콤마로 이어줌. default : localhost:9092
그 외에 여러 가지 옵션이 있는데 그건 Url 참고하기
*/
```
Kafka client 정보를 만들어야 한다. 정보를 만드는건 아주 간단. KafkaClient 클래스를 활용해서 객체를 만들어준다.

### Producer
```
const Producer = kafka.Producer;
const producer = new Producer(client);
```
Producer 객체를 만드는 것은 아주 간단하다. Kafka client 객체를 사용해서 producer를 생성한다. producer엔 두개의 이벤트 핸들러가 존재한다. 
* ready : producer가 모두 준비되고 메세지를 전송할 수 있는 단계가 되면 실행
* error : 준비할 때 에러가 나타나는 경우. 보통 client의 문제로 발생함.
```
producer.on('ready',()=>{
    console.log('kafka producer ready');
});
producer.on('error',(err)=>{
    console.log('error in kafka producer');
    console.log(err);
})
```

producer의 가장 중요한 메세지 전송 방법을 알아보자. 너무나도 간단하게 send메소드를 사용한다.
```
producer.send([{'topic':'chat', 'messages':'연결 되었다 짜식아'}],(err,data)=>{});
```

### Consumer
```
const consumer = new Consumer(client,
    [
        {'topic':'chat',partition:0}
    ],
    {
        autoCommit: false
    }
);
```
Consumer 객체를 만들 때엔 수신할 토픽을 설정해줘야 한다. 배열로 받을 수 있고 오브젝트엔 topic명과 partition을 가진다.    Option엔 url에 더 자세히 나오는데 대표적으로 groupId 설정이나 autoCommit 설정 등이 있다.   
Consumer의 이벤트 핸들러는 message이다. 유추할 수 있듯이 메세지가 들어오면 발동하는 이벤트 핸들러이다.
```
consumer.on('message',function(message){
    console.log(message);
});
```

다음 Day2엔 topic과 메세지 관련한 REST API 설계를 진행할 것이다.
### 참조
[kafka-node](https://github.com/SOHU-Co/kafka-node)