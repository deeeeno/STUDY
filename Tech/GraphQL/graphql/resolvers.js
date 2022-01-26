import {getMovies,getMovieById,getSuggestionsById} from './db';
const resolvers = {
    Query:{
        movies:(_,{limit,rate})=>getMovies(limit,rate),
        movie:(_,{id})=>getMovieById(id),
        suggestions:(_,{id})=>getSuggestionsById(id),
    },
}
export default resolvers