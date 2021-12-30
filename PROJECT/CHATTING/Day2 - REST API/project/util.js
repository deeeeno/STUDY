module.exports = {
    getDate: function(date = new Date()){
        let year = date.getFullYear().toString();

        let month = date.getMonth() + 1;
        month = month < 10 ? '0' + month.toString() : month.toString();

        let day = date.getDate();
        day = day < 10 ? '0' + day.toString() : day.toString();

        let hour = date.getHours();
        hour = hour < 10 ? '0' + hour.toString() : hour.toString();

        let minutes = date.getMinutes();
        minutes = minutes < 10 ? '0' + minutes.toString() : minutes.toString();

        let seconds = date.getSeconds();
        seconds = seconds < 10 ? '0' + seconds.toString() : seconds.toString();

        return `${year}-${month}-${day} ${hour}:${minutes}:${seconds}`;
    }
}