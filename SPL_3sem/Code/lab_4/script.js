//TASK 1
let GoodsList = new Set();
function addToList(ObjtoAdd){
    return GoodsList.add(ObjtoAdd);
}
function deleteFromList(ObjtoDelete){
    return GoodsList.delete(ObjtoDelete);
}
function checkPresense(ObjtoCheck){
    return GoodsList.has(ObjtoCheck);
}
console.group("Goods");
let Good1 = {name:"Computer",price:"200$"};
let Good2 = {name:"Smartphone",price:"100$"};
let Good3 = {name:"SmartWatch",price:"50$"};
addToList(Good1);
addToList(Good2);
addToList(Good3);
console.log(GoodsList);
deleteFromList(Good2);
console.log(GoodsList);
console.log(checkPresense(Good2));
console.groupEnd();
//TASK 2
let Students =new Set();

function addStudent(Student){
    return Students.add(Student);
}
function deleteStudent(Id){
    for(let Stud of Students){
        if(Stud.Id===Id){
            Students.delete(Stud);
        }
    }
    return Students;
}

function groupFilter(GroupNum){
    let chosenGroup = [];
    for(let Stud of Students){
        if(Stud.group===GroupNum){
            chosenGroup.push(Stud);
        }
    }
    return chosenGroup;
}
function groupNumSort(){
    let ArrayToSort = Array.from(Students);
    ArrayToSort.sort((a,b)=>{
        if(a.Id<b.Id){
            return -1;
        }
        if(a.Id>b.Id){
            return 1;
        }
        return 0;
    });
    Students.clear();
    for(let elem of ArrayToSort){
        Students.add(elem);
    }
    return Students;
}
console.group("Students");
let Student1 = {Id:1,group:1,FIO:"Иванов Иван Иванович"};
let Student2 = {Id:2,group:1,FIO:"Качинскас Вацловас Вацловавич"};
let Student3 = {Id:3,group:2,FIO:"Александрова Александра Александровна"};
let Student4 = {Id:8,group:3,FIO:"Щербакова Алина Николаевна"};
addStudent(Student4);
addStudent(Student1);
addStudent(Student3);
addStudent(Student2);
console.log(Students);
deleteStudent(3);
console.log(Students);
console.log(groupFilter(1));
console.log(groupNumSort());
console.groupEnd();

//TASK 3
let ShopingCart = new Map();

function addToCart(Elem){
    let Key = Elem.Id;
    let name = Elem.name;
    let Quantity = Elem.Quantity;
    let Price = Elem.Price;
    let Value = {name,Quantity,Price};
  
    return ShopingCart.set(Key,Value);
}
function deleteByID(Id){
    if(ShopingCart.has(Id)){
        ShopingCart.delete(Id);
    }
    return ShopingCart;
}
function deleteByName(Name){
    for(let [key,value] of ShopingCart){
        if(value.name===Name){
            ShopingCart.delete(key);
        }
    }
    return ShopingCart;
}
function changeQuantity(Id,NewQuantity){
    if(ShopingCart.has(Id)){
        let CurrentElem = ShopingCart.get(Id);
        CurrentElem.Quantity = NewQuantity;
        ShopingCart.set(Id,CurrentElem);
        return ShopingCart;
    }
}
function changePrice(Id,NewPrice){
    if(ShopingCart.has(Id)){
        let CurrentElem = ShopingCart.get(Id);
        CurrentElem.Price = NewPrice;
        ShopingCart.set(Id,CurrentElem);
        return ShopingCart;
    }
}
function countGoodsandPrice(Cart){
    let CartSize = Cart.size;
    let AllPrice = 0;
    for(let [key,value] of ShopingCart){
        AllPrice+=parseInt(value.Price);
    }
    let ToBeReturned = {Size:CartSize,Price:AllPrice};
    return ToBeReturned;
}

console.group("Shoping Cart");
let Shp1 = {Id:1111,name:"Vacuum cleaner",Quantity:2,Price:"200$"};
let Shp2 = {Id:1258,name:"Laptop",Quantity:1,Price:"1500$"};
let Shp3 = {Id:1264,name:"Smartphone",Quantity:3,Price:"300$"};
let Shp4 = {Id:3082,name:"Gaming Console",Quantity:2,Price:"400$"};
let Shp5 = {Id:5470,name:"Wireless Headphones",Quantity:1,Price:"100$"};
addToCart(Shp1);
addToCart(Shp2);
addToCart(Shp3);
addToCart(Shp4);
addToCart(Shp5);
console.log(ShopingCart);
deleteByID(1258);
console.log(ShopingCart);
deleteByName("Vacuum cleaner");
console.log(ShopingCart);
changeQuantity(3082,15);
console.log(ShopingCart);
changePrice(5470,"500$");
console.log(ShopingCart);
console.log(countGoodsandPrice(ShopingCart));
console.groupEnd();

//TASK 4
let Cached = new WeakMap();
function forWeakMap(Obj){
    if(!Cached.has(Obj)){
        let result = Object.keys(Obj).length*3;
        Cached.set(Obj,result);
    }
    return Cached.get(Obj);
}
console.group("WeakMap");
let Obj1 = {name:"Shiman D.V"};
let Obj2 = {name:"Shiman D.V",position:"Dean"};
console.log(forWeakMap(Obj1));
Obj1=null;
console.log(forWeakMap(Obj2));
Obj2 = null;
//console.log(forWeakMap(Obj1)); //will be an error because obj1 is already deleted
console.groupEnd();