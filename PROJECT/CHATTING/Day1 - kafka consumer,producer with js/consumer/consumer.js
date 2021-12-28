const KAFKA_IP = 'localhost:9092';
const kafka = require('kafka-node');

const client = new kafka.KafkaClient({kafkaHost : KAFKA_IP});

const Consumer = kafka.Consumer;

/*
컨슈머 클래스 주요 옵션
Consumer(client, array of fetchRequest, options)
options
groupId : default kafka-node-group
autoCommit : true
*/
const consumer = new Consumer(client,
    [
        {'topic':'chat',partition:0}
    ],
    {
        autoCommit: false
    }
);
consumer.on('message',function(message){
    console.log(message);
});