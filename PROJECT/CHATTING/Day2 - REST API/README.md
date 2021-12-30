# Day2 - DATA, REST API

### DATA
DATA는 크게 3개를 생각했다. 사용자 데이터인 User, 채팅방 정보인 ChatRoom, 메세지인 Message가 있다. DB설계는 다음에 진행 
* User   
<pre>
{
    id : user의 아이디
    name : user의 이름
}
</pre>
* Chat
<pre>
{
    id : 채팅방의 아이디
    name : 채팅방 이름
    masterID : 채팅방을 만든 유저의 아이디
    topic : 채팅방의 토픽
}
</pre>
* Message
<pre>
{
    sender: 발신인
    datetime: 발신 시간
    message : 발신 내용
}
</pre>
### REST API
프로젝트에 필요한 REST API를 만들어보자. 크게 유저, 토픽(채팅방)에 대한 REST API가 있을 것이다(추후 추가되는 API는 완성 후 다룰 예정). 채팅방 하나 당 토픽 하나가 생성되나는 전재를 둘 것이다.   
모든 API에 대해서 response data는 아래의 형식으로 통일한다.
<pre>
{
    'status': 요청이 제대로 완료 시 'success', 오류가 있는 경우 'error'
    'message' : status가 success이면 특정 Object, 실패 시 실패 원인 메세지
}
</pre>
|METHOD|URI|body|response data|설명|
|------|---|---|---|---|
|GET|/topics/{topicID}|-|Chat Object|topicID에 대한 토픽 정보를 가져온다.|
|POST|/topics/{topicID}|토픽에 대한 옵션|success message|topicID인 토픽을 생성한다.|
|DELETE|/topics/{topicID}|-|success message|topicID인 토픽을 삭제한다.|
|POST|/topics/{topicID}/messages|Message Object|success message|topicID에 대해서 메세지를 전송한다.|
|GET|/users/{userID}|-|User Object|userID인 유저 정보를 가져온다.|
|GET|/users/{userID}/topics|-|Chat Object list|유저가 가진 토픽 리스트를 가져온다.|
|POST|/users/{userID}/topics{topicID}|-|Chat Object|userID유저가 topicID인 채팅방을 만든다.|
|PUT|/users/{userID}/topics{topicID}|-|success Message|userID유저가 topicID인 채팅방을 들어간다.|