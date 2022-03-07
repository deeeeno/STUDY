# Property Drilling

리액트 컴포넌트 A는 B를 자식으로 가지고, B는 C 컴포넌트를 자식으로 가지는 구조로 생각해보자. 이 상황에서 A의 x값을 C 컴포넌트에서 사용하고자 한다면 아래의 코드 구조가 될 것이다.
```
function A(){
    const [x,setX] = useState('')
    return(
        <>
        <B x={x}/>
        </>
    )
}
function B({x}){
    return (
        <>
        <C x={x}/>
        </>
    )
}
function C({x}){
    return (
        <>
        <div>{x}</div>
        </>
    )
}
```
B 컴포넌트는 x를 쓰지도 않은데 C에 전달하기 위해 property로 x를 가지게 되는 것이다. 이를 **Property Drilling**이라고 한다.   이 레포지토리에선 이런 드릴링을 방지하고자 사용하는 **Redux(with react), Context**에 대해서 알아보자!