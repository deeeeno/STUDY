# Context
이전 Property Drilling에서 보았듯이, 사용하지 않는 데이터를 전달을 하기 위해 프로퍼티로 계속 전달해야 하는 경우가 나타난다. 이를 방지하는 첫 번째 방법인 **Context**를 알아보자.   
[공식문서](ko.reactjs.org/docs/context.html)을 살펴보면 context는 이렇게 설명된다.   
> context를 이용하먄 단계마다 일일이 props를 넘겨주지 않고도 컴포넌트 트리 전체에 데이터를 제공할 수 있습니다.   
말 그대로 context를 이요하면 컴포넌트 트리 단계마다 넘겨주지 않고 값을 공유하도록 할 수 있다.

## Usage
거두절미하고 사용법부터 알아보자! 우리가 사용하게 될 메소드는 react의 **createContext, useContext** 그리고 **Provider**이다.    
`import {useContext, createContext} from 'react'`   
### createContext
이름에서 알겠듯이 Context를 생성하는 것이다. 상당하게 간단한데 사용법은 아래와 같다.   
`const Context이름 = createContext(default 값);`   
```
const defaultValue = { text: 'hihi' }
const TextContext = createContext({
    value:defaultValue,
    setValue:()=>{}
})
```
### Provider
만들었으니 제공을 먼저 해야한다. 컴포넌트에 사용하도록 제공하는 것은 Provider를 사용해서 감싸주는 방법이다.
```
function App(){
    const [value,setValue] = useState(defaultValue);
    return(
        <>
        //설정한 Context의 Provider를 사용한다.
        <TextContext.Provider value={value,setValue}>
            <Text/>
        </TextContext.Provider>
        </>
    )
}
```

### useContext
제공했으니 이제? 사용만 하면 된다. 사용할 때에는 Consumer를 사용하는 방법도 있으나 우리는 useContext라는 Hook을 사용해보자.   
```
function Text(){
    //useContext(Context 이름).
    //이 경우 TextContext를 import 해주어야 한다.
    const {value,setValue} = useContext(TextContext);
    const onChange = (e) => {
        setValue({ ...value, text: e.target.value })
    }
    return (
        <div>
            <div>{value.text}</div>
            <input onChange={onChange} />
        </div>
    )
}
햔제 Text 컴포넌트를 감싸고 있는 Context Provider의 value는 App 컴포넌트의 state로 지정된 value와 modifier인 setValue이다. 이를 통해서 property를 거치지 않고 데이터를 공유하는 Context 사용법을 간단하게 알아보았다.
```
### When we use?