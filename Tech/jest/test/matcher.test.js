test('toBe',()=>{
    expect(123).toBe(123);
    const abc = {a:123};
    //expect({a:123}).toBe(abc);
    expect(abc).toBe(abc);
});
test('toEqual',()=>{
    expect(123).toEqual(123);
    const abc = 123;
    expect(abc).toEqual(123);
    //expect(abc).toEqual('123');
});
test('toBeTruthy toBeFalsy',()=>{
    expect(123).toBeTruthy();
    expect(0).toBeFalsy();
});
test('toHaveLength toContain',()=>{
    const phone = ['iPhone','Galaxy','BlackBerry'];
    expect(phone).toHaveLength(3);
    //expect(phone).toContain('Vega')
});
test('toMatch',()=>{
    const email = 'kkrs0512@naver.com';
    const not_email = 'kkrs0512';
    expect(email).toMatch(/.*\@.*/);
    //expect(not_email).toMatch(/.*\@.*/);
});
test('toThrow',()=>{
    function errorfunc(){
        try{
            a = 1;
        }catch(e){
            throw e;
        }
    }
    expect(()=>errorfunc()).toThrow();
});
