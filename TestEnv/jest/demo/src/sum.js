function add(...numbers){
    const a = numbers.reduce((acc,val)=> acc+val,0);
    return a
}
export default add;