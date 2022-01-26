
import fetch from 'node-fetch';

export const getMovies = async (limit=10,rate=9)=>{
    const response = await fetch(`https://yts.am/api/v2/list_movies.json?limit=${limit}&minimum_rating=${rate}`);
    const json = await response.json();
    return json.data.movies;
};

export const getMovieById = async(id)=>{
    const response = await fetch(`https://yts.mx/api/v2/movie_details.json?movie_id=${id}`);
    const json = await response.json();
    return json.data.movie;
}
export const getSuggestionsById = async(id)=>{
    const response = await fetch(`https://yts.mx/api/v2/movie_suggestions.json?movie_id=${id}`);
    const json = await response.json();
    return json.data.movies;
}