import { serve, ServerRequest } from "https://deno.land/std@0.92.0/http/server.ts";
import { pathToRegexp } from "https://raw.githubusercontent.com/pillarjs/path-to-regexp/master/src/index.ts";
import router from  './routers.ts'


const server = serve({hostname:"0.0.0.0",port:8080});
console.log("server running...... localhost:8080");

for await(const request of server){
    router(request);
}