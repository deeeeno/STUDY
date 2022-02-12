import userService from '../src/users';
beforeAll(()=>{
    console.log('테스트 전 모두 지우기');
    userService.destroyAll();
});
afterAll(()=>{
    console.log('테스트 후 모두 지우기');
    userService.destroyAll();
});
beforeEach(()=>{
    console.log('테스트 전 전처리~');
    userService.create({id:1,name:'aino'},
    {id:2,name:'cino'},
    {id:3,name:'bino'},
    {id:4,name:'dino'});
})
afterEach(() => {
    console.log('테스트 종료 후 후처리~');
    userService.destroyAll();
});

test('userService findAll test',()=>{
    expect(userService.findAll().length).toEqual(4);
});

test('userService find test',()=>{
    const dino = userService.find(4);
    expect(dino.name).toEqual('dino');
});

describe('userService find relay test',()=>{
    beforeAll(()=>console.log('find relay describe beforeAll'));
    afterAll(()=>console.log('find relay describe afterAll'));
    beforeEach(()=>console.log('find relay describe beforeEach'));
    afterEach(()=>console.log('find relay describe afterEach'));
    test('find id 1',()=>{
        console.log('id 1');
        const dino = userService.find(1);
        expect(dino.name).toEqual('aino');
    });
    test('find id 2',()=>{
        console.log('id 2');
        const dino = userService.find(2);
        expect(dino.name).toEqual('cino');
    });
    test('find id 3',()=>{
        console.log('id 3');
        const dino = userService.find(3);
        expect(dino.name).toEqual('bino');
    });
    test('find id 4',()=>{
        console.log('id 4');
        const dino = userService.find(4);
        expect(dino.name).toEqual('dino');
    });
});