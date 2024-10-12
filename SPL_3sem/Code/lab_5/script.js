//TASK 1
function volume(length){
    return (width,height)=>{
        return length*width*height;
    }
}
const len_const = 120;
console.group("Volume");
console.log(volume(len_const)(130,140));
console.log(volume(len_const)(50,10));
console.log(volume(len_const)(110,15));
console.groupEnd();
//TASK 2

