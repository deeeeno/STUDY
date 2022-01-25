### GraphQL
over-fetching   - 내가 요청한 정보보다 더 많은 것들을 주는 경우 -> 개발자가 뭘 받은지 정확하게 모름 비효율인 경우가 있을 수 있어.   
under-fetching   - 하나를 완성하기 위해 여러 요청들을 하는 경우 생김. 즉, 하나의 요청으로 끝나는게 아니라 여러 요창을 통해 완성되는 것을 의미   
그래프큐엘은 위 경우를 해결해줄 수 있다.
```
/feed
/notifications
/users/1

총 3가지 정보를 요청하게 되면 under-fetching, over-fetching이라고 가정하자.
graphql로 고치면
query{
    feed{
        comments    //필요한 정보만 써버리기
        likeNumber
    }
    notifications{
        isRead
    }
    user{
        username
        profilePic
    }
}

요런식으로 언더페칭과 오버페칭을 해결가능
```



### 추가 정리 
* graphQL   
* graphql-yoga   
* schema.graphql 작성법   
* resolver   

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