# React - 07. useRef

이전 ![제어, 비제어 컴포넌트](./05.1 - 제어, 비제어 컴포넌트.md)에서 간단하게 소개된 **ref**의 사용법에 대해서 알아보자.   
React 내부 상태로써 관리되지 않는 컴포넌트를 우리는 비제어 컴포넌트라고 하였다. 이들은 DOM에서 관리가 되고 있다. 간혹 우리는 DOM의 데이터를 접근해야 하는 경우가 있을 것이다. 그런 경우 **ref**를 사용한다.   
### ref 생성 & 할당
ref 생성에 대해서 우리는 **useRef**라는 React Hook을 알아보자. 사용법은 간단하다.
```
const testRef = useRef();
```
사실 ref를 생성하는 것 보다 태그에 지정해주는 것이 더 중요하다. 아래 state로 관리되는 제어 컴포넌트와 비제어 컴포넌트 예시를 보면서 살펴보자.
```
function App(){
    const [stateText,setST] = useState('')      //state로 관리되는 텍스트
    const textRef = useRef();                   //text ref
    const onSubmit = (e)=>{
        e.preventDefault();
        console.log(state);
        console.log(textRef.current.value);
    }
    return(
        <>
        <form onSubmit={onSubmit}>
            state : <input onChange={(e)=>setST(e.target.value)}/>
            ref : <input ref={textRef}/>
            <button type="submit">
        </form>
        </>
    )
}
```
이전에도 다뤘지만 두가지의 가장 큰 다른 점은 state는 modifier를 통한 실시간 동기화가 가능하지만, ref로 연결된 컴포넌트는 vanillaJS와 비슷하게 이벤트 트리거가 발생되어야 값이 정해진다는 것을 알 수 있다.   

### 자식 컴포넌트 내 태그에 ref 할당
```
function App(){
    const textRef = useRef();
    return(
        <Text ref={textRef}/>
    )
}
function Text(){
    return(
        <div>
            <input id="target"/>
        </div>
    )
}
```
이번엔 좀 다른 경우를 살펴보자. 처음에 보았던 예시와 다른 점은 자식 컴포넌트 내 태그에 ref를 부여해야 한다는 점이다. 아쉽게도 react 컴포넌트는 ref가 될 수 없다. 이런 경우엔 **forwardRef**을 사용해야 한다.
```
const Text = forwardRef((prop,ref)=>{
    return(
        <div>
            <input ref={ref} id="target"/>
        </div>
    )
})
```
