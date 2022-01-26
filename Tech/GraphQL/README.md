# GraphQL
### REST API의 한계
REST Api는 리소스들을 하나의 엔드포인트로 관리하는 API로 단순하게 사용할 수 있다. 하지만 서비스가 복잡해지거나 데이터 요청사항이 많아지는 경우 over-fetching, under-fetching이 발생할 수 있다.
```
over-fetching   // 사용할 데이터를 위해 요청했는데 더 많은 데이터를 받는 경우. 개발자가 뭘 받은지 정확하게 몰라 비효율인 경우가 있음.
under-fetching  // 한개의 페이지 혹은 기능을 완성하기 위해 여러 요청을 해야하는 경우.  
```
또한 서비스가 커져감에 따라서 REST API는 리소스 별 새로운 엔드포인트를 가지기 때문에 비슷하지만 다른 API를 생성해야 하는 단점이 있다.   
이런 부분을 해결하고자 나타난게 **GraphQL**이다.

### What is GraphQL?
```
query{
    Hello(name:"world"){
        message
    }
}

{
    "data":{
        "hello":{
            message:"Hello World"
        }
    }
}

```
GraphQL은 facebook에서 만든 것으로 Graph Query Language, 즉 쿼리 언어이다. GraphQL은 웹 클라이언트가 데이터를 서버로부터 효율적으로 가져오는 것을 목적으로 하고 있다.   
REST API와는 다르게 하나의 엔드포인트를 가지고 있어서 단 한번의 네트워크 호출로 처리가 가능하도록 한다. 이것으로 Under-fetching을 해결할 수 있다.   
또한 REST API는 서버에서 주는 정보 그대로 클라이언트가 받기 떄문에 사용하지 않는 정보를 전부 받게 되지만, graphQL은 받고자 하는 정보를 명시함으로써 필요없는 정보를 받지 않을 수 있다. 이를 통해 over-fetching을 해결할 수 있다.   
```
//예를 들어 인스타그램 화면을 구성하기 위해 피드, 알림, 유저정보가 필요하다면 REST API로는 아래의 요청들을 진행할 것이다.
/feed
/notifications
/users/1

//하지만 GraphQL은 단 하나의 엔드포인트로 아래와 같이 요청할 수 있다.
query{
    feed{
        comment         //필요한 정보만 요청
        likeNumber
    }
    notification{
        isRead
    }
    user{
        username
        profilePic
    }
}
```
### GraphQL PipeLine
![pipeline](/Tech/resources/graphql-pipeline.png)

### GraphQL의 단점
위처럼 사이즈를 줄이거나 요청 횟수를 줄이는 장점만 가지고 있다면 얼마나 좋겠지만, 당연히 단점도 가지고 있다.   
* File 전송 등 텍스트만으로 하기 힘든 내용 처리가 복잡하다.   
* 고정된 요청, 응답만 필요한 경우엔 REST API보다 크기가 커지는 경우도 존재한다.   
* 재귀적인 Query가 불가능하다.
* 캐싱을 사용하는데 어려움이 있다.

### When to use?
그럼 언제 GraphQL을 사용하고 언제 REST API를 사용하게 되는 것일까?
* GraphQL   
서로 다른 다양한 요청들에 대해 응답할 수 있어야 할 때   
대부분의 요청이 CRUD인 경우   
* REST API   
캐싱을 잘 활용하고 싶을 때   
파일 전송 등 다소 복잡한 요청들이 존재할 때   
요청의 구조가 정해져 있을 때   

### GraphQL 핵심
* schema   
GraphQL의 스키마는 result의 오브젝트 타입, query,mutation의 타입 등을 의미한다. 스키마를 작성하는 법은 다음과 같다.
```
type (오브젝트 타입 명){
    (필드명):(필드 타입)
    (필드명):(필드 타입)!
}

#query,mutation의 타입 스키마 작성
type (Query,Mutation){
    종류 이름(arg1:arg1Type!, arg2:arg2Type ...) : return 오브젝트 타입
}

```
작성법은 비교적 간단한데 집고 넘어가야 할 부분은, 느낌표(!), 대괄호([])이다. 느낌표는 non-nullable임을 나타내는 것으로 null이 아니란 것을 명시하는 것이고, 대괄호는 배열을 의미한다. 예시 스키마 작성은 다음과 같다.
```
type Movie{
    id:Int!
    title:String!
    rating:Float!
    summary:String!
    language:String!
    medium_cover_image:String!
}

type Query{
    movies(limit:Int!,rate:Float!): [Movie]!
    movie(id:Int!):Movie
    suggestions(id:Int!):[Movie]
}
```
* resolver
파이프라인에서 보았듯이 resolver가 필요하다. 쿼리에 맞춰 요청한 액션에 대해서 데이터 CRUD에 대한 구체적인 과정이 필요할 것이다. 이 구체적인 과정에 대해 설명하는 것이 resolver이다.   
resolver에는 query,mutation 종류에 대해서 실행될 콜백 함수를 명시해준다.   
javascript를 사용한다면 **graphql-yoga**를 사용하게 될 텐데 중요한 것은 스키마에서 명시한 Query타입에 맞춰 설정해줘야한다는 것이다.
```
const resolvers = {
    Query:{
        /*
        쿼리 명 : 쿼리에 따른 콜백 함수 argument는 객체로 들어온다.
        */
        movies:(_,{limit,rate})=>getMovies(limit,rate),
        movie:(_,{id})=>getMovieById(id),
        suggestions:(_,{id})=>getSuggestionsById(id),
    },
}
```
* query & mutation
두개의 큰 차이는 CRUD에 있다. query는 Read라고 생각하면 되고, mutation은 나머지 Create,Update,Delete로 생각할 수 있다.
* mutation


### 추가 정리 
* graphql-yoga   
* operation query type

### useful error log
```
"Field \"person\" of type \"Person!\" must have a selection of subfields. Did you mean \"person { ... }\"?",
 -> 스키마에서 타입을 지정하고 해당 타입이 객체라면 하위 키, 밸류가 있을 것이지. 이런 구조인 경우 스키마에 설정한 타입에 대해서
    어떤 데이터를 받을지 설정해줘야함
query{
    person{
        name //이렇게
        age
    }
}
```