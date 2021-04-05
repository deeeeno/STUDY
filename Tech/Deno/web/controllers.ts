import { serve, ServerRequest } from "https://deno.land/std@0.92.0/http/server.ts";
import { pathToRegexp } from "https://raw.githubusercontent.com/pillarjs/path-to-regexp/master/src/index.ts";

export async function mainHandler(req:ServerRequest, match:RegExpExecArray){
    console.log('main');
    req.respond({
        body:"MAIN SITE"
    })
}
export async  function notfound(req:ServerRequest){
    console.log('404');
    req.respond({
        body:"404 Page Not Found"
    })
};

export async  function pingPongHandler(req:ServerRequest, match:RegExpExecArray){
    const ppText:string = String(match[1]);
    console.log(ppText);
    req.respond({
        body:ppText
    });
}