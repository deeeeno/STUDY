describe('jest mock -> mock.fn',()=>{

    test('mock function 중 mockReturnValue 사용 테스트',()=>{
        const mockFn = jest.fn();
        mockFn.mockReturnValue(1);
        expect(mockFn()).toEqual(1);
    });


    test('mock function 중 mockResolvedValue 사용 테스트',(done)=>{
        const mockFn = jest.fn();
        mockFn.mockResolvedValue(1);
        mockFn().then((result)=>{
            expect(result).toEqual(1);
            done();
        });
    });

    test('mock function 중 mockImplementation 사용 테스트',()=>{
        const mockFn = jest.fn();
        mockFn.mockImplementation((name)=>`hi ${name}`);
        expect(mockFn('dino')).toEqual("hi dino");
    })

    test('mock function matcher 1 -> toBeCalledTimes',()=>{
        const mockFn = jest.fn();
        mockFn();
        mockFn();
        mockFn();
        mockFn();
        mockFn();
        expect(mockFn).toBeCalledTimes(5);
    });

    test('mock function matcher 1 -> toBeCalledWith',()=>{
        const mockFn = jest.fn();
        mockFn(1);
        mockFn(2);
        mockFn({1:2});
        mockFn([1,2]);
        expect(mockFn).toBeCalledWith(1);
        expect(mockFn).toBeCalledWith(2);
        expect(mockFn).toBeCalledWith({1:2});
        expect(mockFn).toBeCalledWith([1,2]);
    });
});
describe('jest spy -> jest.spyOn',()=>{

    test('jest spyOn tutorial',()=>{
        const calculator = {
            'add':(a,b)=>a+b
        }
        const addSpy = jest.spyOn(calculator,'add');
        const result = calculator.add(1,2);

        expect(addSpy).toBeCalledTimes(1);
        expect(addSpy).toBeCalledWith(1,2);
        expect(result).toEqual(3);
    })
});
const axios = require('axios');
describe('spy, mock function 사용해보기 to axios get',()=>{
    test('axios get에 스파이 붙이기', async ()=>{
        //axios의 get함수에 spy
        const getSpy = jest.spyOn(axios,"get");

        const ret = await axios.get('http://localhost:5000/test');
        console.log(ret.data);
        expect(getSpy).toBeCalledTimes(1);
        expect(getSpy).toBeCalledWith('http://localhost:5000/test');
        expect(ret.data).toHaveProperty('test','jest test');
    })

    test('axios get mock function 붙이기', async ()=>{
        //axios의 get을 의존할 수 없으므로 mock function을 통해 변경
        axios.get = jest.fn().mockResolvedValue({data:{'test':'jest test'}});
        
        const ret = await axios.get('http://localhost:5000/test');
        
        expect(ret).toHaveProperty('data',{'test':'jest test'});
        expect(ret.data).toHaveProperty('test','jest test');
    })
});