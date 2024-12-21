class Task{
    constructor(id,name){
        this.id = id;
        this.name = name;
        this.state = "not done";
    }

    changeName(value){
        this.name = value;
    }
    changeState(value){
        if(!(typeof value==="string")||!(value.toLowerCase==="done")||!(value.toLowerCase==="not done")){
            throw new Error("State error");
        }
        this.done = value;
    }
};

class ToDoList{
    constructor(id,name){
        this.ToDoList = [];
        this.id = id;
        this.name = name;
    }

    changeName(value){
        this.name = value;
    }

    addTask(){
        let current_task = new Task(arguments[0],arguments[1]);
        this.ToDoList.push(current_task);
    }

    filterTask(state){
        console.group(this.name+" filtered by "+state);
        this.ToDoList.forEach(task => {
            if(task.state==state){
                console.log(task);
            }
        });
        console.groupEnd();
    }

    printList(){
        console.group(this.name);
        this.ToDoList.forEach(task => {
            console.log(task);
        });
        console.groupEnd();
    }
    changeTaskState(task,state){
        for(let i=0;i<this.ToDoList.length;i++){
            if(this.ToDoList[i].name.toLowerCase===task.toLowerCase){
                this.ToDoList[i].state = state;
                break;
            }
        }
    }
};

let List1 = new ToDoList(1,"My domestic list");
List1.addTask(1,"Clean the kitchen");
List1.addTask(2,"Cook dinner");
List1.ToDoList[0].changeName("CHANGED");
List1.printList();
List1.changeTaskState("Clean the Kitchen","done");
List1.printList();
List1.filterTask("not done");

let List2 = new ToDoList(2,"My work list");
List2.addTask(1,"Finish final build development");
List2.addTask(2,"Start new app development");
List2.addTask(3,"Sell new app idea");
List2.printList();
List2.changeTaskState("start new app development","done");
List2.printList();
List2.filterTask("not done");
List2.changeName("My programming list");
List2.printList();