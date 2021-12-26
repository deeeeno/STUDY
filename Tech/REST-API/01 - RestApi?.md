# REST API
### API?
API는 Application Programming Interface의 약자로 응용 프로그램(Application)에서 사용할 수 있도록 프로그래밍 언어가 제공하는 기능을 제어하도록 하는 Interface를 말한다.
### REST?
REST 아키텍쳐는 Representational State Transfer의 약자로 리소스를 명시하고 HTTP 메소드를 통해 자원의 CRUD를 적용하는 모든 것을 의미한다. REST구조는 아래의 구성요소를 가지고 있다.
1. Resource : 리소스! 자원!
2. Verb : 리소스의 액션을 정의한다. 주로 HTTP Method로 표현한다.
3. Representations : 리소스 행위에 대한 내용을 정리한다.
### REST API?
핵심 콘텐츠 및 기능을 외부 사이트에서 사용할 수 있도록 REST 아키텍쳐를 이용한 API를 의미한다. REST APi는 아래의 스타일을 갖춰야 한다고 한다.   
1. Client <-> Server
	서버는 API를 제공하고, 클라이언트는 세션, 정보들을 직접 관리하는 구조로 명확하게 나뉘어져야 한다.
2. Stateless
	REST API는 상태정보를 따로 저장, 관리하지 않는다. API 서버는 들어오는 request만 처리하면 되지, 세션, 쿠키 정보를 별도로 저장하지 않는다.
3. Cache
	REST는 HTTP를 사용하고, HTTP 웹 표준을 그대로 따른다. 즉, HTTP가 가진 캐싱 기능이 적용 가능하다.
4. Uniform Interface
	URI로 지정한 리소스에 대해서 조작을 통일하고 한정적인 인터페이스로 수행하는 스타일인 유니폼 인터페이스를 유지해야 한다.
	리소스가 URI로 식별되어야 하고, 리소스에 대한 액션을 HTTP 메세지에 표현해서 전송해야 한다. 또한 메세지는 직관적으로 보여야한다.
5. 계층 구조
	다중 계층으로 구성될 수 있다.
6. Self-descriptiveness
	별도 문서 없이 내용만 보고도 쉽게 이해할 수 있어야 한다.

### Pros Of REST API
1. HTTP 프로토콜을 사용하기 때문에 별도의 인프라 구축이 필요 없다.
2. HTTP 프로토콜의 표준을 활용해서 캐싱과 같은 추가 장점을 함께 가져갈 수 있다.
### Cons Of REST API
1. HTTP Method을 활용한 액션 정의를 하기에 형태가 제한적이다(GET,POST,DELETE,PUT).
2. PUT,DELETE의 경우 구형 브라우저에서는 지원하지 않는다.

### REST API Rule
1. URI의 정보엔 Resource(자원)을 나타내야 한다. 리소스는 명사, 소문자를 사용하고, 복수 명사를 사용하는 것이 좋다.   
<pre>GET /Tech/Student/jane -> GET /tech/students/jane</pre>
2. 리소스의 액션은 HTTP Method로 나타낸다. URI에 액션에 대한 내용이 들어가면 안된다.   
<pre>GET /students/delete/jane -> DELETE /students/jane</pre>
3. 슬래시(/)는 계층 관계를 나타낼 때 사용하고, 마지막 문자로는 포함하지 않는다.   
4. 하이픈(-)은 가독성을 높이는 데에 사용 가능하다.
5. 파일 확장자는 URI에 포함시키지 않고, Accept Header를 사용한다.   
<pre>http://restapi.example.com/members/soccer/345/photo.jpg (X)
  
GET / members/soccer/345/photo HTTP/1.1 Host: restapi.example.com Accept: image/jpg (O)</pre>
6. 리소스 간 연관 관계가 있으면 /리소스명/리소스ID/관계가 있는 리소스명 으로 다룬다(일반적으로 소유관계).
