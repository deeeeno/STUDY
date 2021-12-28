const KAFKA_IP = 'localhost:9092';
const kafka = require('kafka-node');

const client = new kafka.KafkaClient({kafkaHost : KAFKA_IP});
/*
KafkaClient -> 카프카 브로커에 직접 연결하는 오브젝트.
주요 파라미터
kafkaHost : 연결할 카프카 호스트 여러개면 콤마로 이어줌. default : localhost:9092
*/

const Producer = kafka.Producer;
const KeyedMessage = kafka.KeyedMessage;

const producer = new Producer(client);
/*
producer object엔 두가지 이벤트핸들러가 존재.
ready : 프로듀서가 메세지를 보낼 수 있는 상태가 됨
error : client에서 문제가 생겼을 때.
*/
const km = new KeyedMessage('key','message');

producer.on('ready',()=>{
    console.log('kafka producer ready');
    producer.send([{'topic':'chat', 'messages':'연결 되었다 짜식아'}],(err,data)=>{
    })
});
producer.on('error',(err)=>{
    console.log('error in kafka producer');
    console.log(err);
})

module.exports = producer;