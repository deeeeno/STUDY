beforeAll(()=>console.log('전역 beforeAll'));
afterAll(()=>console.log('전역 afterAll'));
beforeEach(()=>console.log('전역 beforeEach'));
afterEach(()=>console.log('전역 afterEach'));


describe('describe No 1',()=>{
    beforeAll(()=>console.log('describe No 1 beforeAll'));
    afterAll(()=>console.log('describe No 1 afterAll'));
    beforeEach(()=>console.log('describe No 1 beforeEach'));
    afterEach(()=>console.log('describe No 1 afterEach'));

    test('test1 of describe No 1',()=>{
        console.log('test1 of describe No 1');
        expect(1).toEqual(1);
    });
    test('test1 of describe No 2',()=>{
        console.log('test1 of describe No 2');
        expect(1).toEqual(1);
    });
    test('test1 of describe No 3',()=>{
        console.log('test1 of describe No 3');
        expect(1).toEqual(1);
    });
})