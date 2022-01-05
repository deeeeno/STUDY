import Button from "./Button";
import styles from './App.module.css';
import {useState, useEffect} from 'react';
function App() {
  const [counter,setCounter] =  useState(0);
  console.log(counter);
  const [keyword,setKeyword] = useState('');

  const onClick = ()=> setCounter((prev)=>prev+1);
  const onChange = (event)=>{setKeyword(event.target.value)};
  
  useEffect(()=>{
    console.log('CALL API')
  },[]);
  useEffect(()=>{
      console.log("SEARCH FOR",keyword);
  },[keyword]);
  useEffect(()=>{
    console.log('counter');
  },[counter]);
  
  return (
    <div>
      <input type="text" onChange={onChange} placeholder="Search here..."/>
      <h1 className={styles.title}>Welcome back!</h1>
      <button onClick={onClick}>click</button>
      <div>{counter}</div>
    </div>
  );
}

export default App;
