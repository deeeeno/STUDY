
const get = (cb)=>{
    setTimeout(()=>{
        cb('test');
    },500);
}
const getPromise = (str)=>{
    return new Promise((resolve)=>{
        setTimeout(()=>{
            resolve(str);
        },500);
    });
}
test('비동기 처리 테스트',(done)=>{
      get((data)=>{
          console.log('hihi');
          expect(data).toEqual('test');
          done();
      });
});
test('프로미스 비동기 처리 테스트',()=>{
    return getPromise('test').then((str)=>{
        expect(str).toEqual('test');
    });
});

test('프로미스 async/await', async ()=>{
    const str = await getPromise('test');
    expect(str).toEqual('test');
});