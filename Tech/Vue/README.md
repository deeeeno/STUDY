# Vue

### Vue
MVVM 패턴의 ViewModel 레이어에 해당하는 화면단 라이브러리이다.   
양방향 데이터 바인딩을 제공하여 view에서 데이터가 수정이 되어도 model의 데이터에 함께 반영이 되고, 그 역도 가능하다.   
컴포넌트 간의 통신은 부모 -> 자식으로 단방향 흐름을 사용하며 최상위 루트 컴포넌트 부터 트리 형식으로 컴포넌트가 생성된다. 가볍고, 빠르며 쉽게 접근이 가능하다.

### MVVM Pattern
Model - ViewModel - View 패턴으로 MVC 패턴 방식에서 기인하였다.  View는 사용자가 보는 화면을 의미하고, 유저의 명령을 받으면 ViewModel로 하달한다.   
ViewModel은 view를 표현하기 위한 model이 된다. view와 데이터 바인딩을 진행하고 view에게서 받은 액션에 대해서 업데이트한다. Model은 데이터, 로직 등으로 구성되어 있고, 실질적인 데이터들을 말한다.
* Pros
View와 Model은 서로 독립적이다. View, viewModel이 바인딩하기에 코드가 줄어든다.
* Cons
데이터 바인딩이 필수적으로 요구된다. 복잡해질수록 viewModel이 방대해진다. 표준화된 툴이 없다.

### Life Cycle
Vue 컴포넌트가 브라우저 화면에 그려지고 사라지기 까지의 과정을 나타내는 라이프 사이클이 존재한다. 여러 단계가 있고 vue는 개발자가 사용할 수 있는 여러 hook이 존재한다.   
* Creation
말그대로 vue 컴포넌트가 생성이 되는 단계이다. 훅으로 beforeCreate, created가 존재한다.   
이 단계에서는 virtualDOM에도 없고, DOM 트리에 반영이 되지 않기 때문에 id, class에 대해서 DOM에 접근할 수 없다.  
훅 중 대표적으로 쓰이는 created에는 컴포넌트의 데이터에 접근이 가능하여 서버로부터 데이터 요청을 하고 초기값을 설정해준다.
* Mounting
virtualDOM이 브라우저 DOM에 삽입되는 단계이다.  
이 중 mounted 훅은 DOM에 삽입이 되고 난 후 실행되는 훅이다. 하지만 완전하게 삽입이 된 상태를 보장하지 않기 떄문에 DOM구조를 조작하는 로직을 사용하기엔 힘들다.  
사용하려면 nextTick 메소드를 통해 진행할 수 있다.
* Updating
데이터가 변경이 되어 html이 수정될 떄 일어나는 단계이다. beforeUpdate, updated 훅이 존재하고, DOM에 패치가 완료된 후 updated 훅이 실행된다.
* Detruction
뷰 컴포넌트가 해제되는 단계이다. 해제가 완료되면 destroyed 훅이 실행된다.

### v-on, v-bind, v-model
뷰는 양방향 바인딩을 지원한다. 또한 단방향성 바인딩 방법도 존재하는데,이러한 바인딩에 사용되는 태그들은 다음과 같다.   
* v-on   
event 핸들링에 대한 바인드를 진행하는 태그이다. 약어로 @로 나타낼 수 있다. 예를 들어 click 이벤트에 대한 핸들러를 바인딩하는 경우 v-on:click or @click으로 나타낸다.
* v-bind   
viewModel의 데이터 update에 대해서 view에 바인드 시켜주는 태그이다. v-bind:id or :id로 사용 가능하다.
* v-model
v-bond처럼 viewModel의 데이터 update에 대해서 데이터 바인드도 가능하지만, 추가적으로 view에서의 데이터 업데이트가 viewModel에도 반영이 된다.
```
<input v-model="value"/>
```