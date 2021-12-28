# PROJECT - CHAT SITE WITH KAFKA
### 개요
kafka 파이프라인을 사용한 채팅 서버를 만들어 본다. 
### Language, Library
Language : Javascript 
Framework : node’s for server, react, vuejs for frontend
Pipeline : Kafka
### 구조
![](/PROJECT/resources/arch.jpg)
아직 확정은 아니지만… 카프카의 토픽을 통해서 클라이언트에게 메세지를 받고, 해당 메세지를 전파해주는 형식을 만들 계획이다. 즉 클라이언트가 프로듀서이자 컨슈머인 것!   
또한 채팅 방 마다 토픽을 둘지 토픽 하나를 통해 모든 메세지를 통하게 할지는 미정..
### 목표 
	1. nodejs를 통한 서비스 만들기
	2. 카프카에 대해 정리 확실히 하기
	3. React 익히기
### Reference
[LINE에서 Kafka를 사용하는 방법 - 1편 - LINE ENGINEERING](https://engineering.linecorp.com/ko/blog/how-to-use-kafka-in-line-1/)   
[kafka-node](https://github.com/SOHU-Co/kafka-node)

### STEP
* Day1) nodejs를 사용해서 Kafka REST producer 초안 만들기 및 consumer 초안 만들기