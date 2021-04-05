//여기엔 핸들러 함수를 쓰자
import { serve, ServerRequest } from "https://deno.land/std@0.92.0/http/server.ts";
import { pathToRegexp } from "https://raw.githubusercontent.com/pillarjs/path-to-regexp/master/src/index.ts";
import {mainHandler, pingPongHandler, notfound} from './controllers.ts';

interface Route{
    name: string; // 라우터 이름
    path: string; // 라우터 경로
    handler:(req:ServerRequest,match:RegExpExecArray) => void; // 라우터 핸들러
}

const routes: Route[] = [
    {name: "main", path:"/", handler:mainHandler},
    {name: "pingpong", path:"/pp/:str", handler: pingPongHandler}
];

function router(request:ServerRequest){
    for(let route of routes){
        const reg = pathToRegexp(route.path);
        const match = reg.exec(request.url);
        if(match) return route.handler(request,match);
    }
    return notfound(request);
}

export default router;