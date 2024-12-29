//get elements from a document
var start_button = document.getElementById('start');
var clear_buttom = document.getElementById('clear');
var generate_button = document.getElementById('gen');
var renew_button = document.getElementById('renew');
var field_container = document.getElementById('sud');

//sudoky game class

class Sudoku{
    constructor(){
        this.field = document.querySelector('.game');
        this.board = Array.from({ length: 9 }, () => Array(9).fill(0));
        this.inputs = [];
        this.generateFiled();
    }
    generateFiled(){
        for(let row = 0;row<9;row++){
            for(let column=0;column<9;column++){
                const inp = document.createElement('input');
                inp.type = 'number';
                inp.min = '1';
                inp.max = '9';
                this.inputs.push(inp);
                this.field.appendChild(inp);

                inp.addEventListener('input',(val)=>{
                    const inputed_val = parseInt(val.target.value, 10);
                })
            }
            this.field.appendChild(document.createElement('br'));
        }

        
    }
}

let sud = new Sudoku();
