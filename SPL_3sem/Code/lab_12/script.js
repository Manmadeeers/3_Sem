
var submit_button = document.getElementById('submit-button');
var form_row = document.getElementById('row');
var form_col = document.getElementById('col');
var form_val = document.getElementById('val');
submit_button.addEventListener('click',()=>{
    sud1.addValue(form_row.value,form_col.value,form_val.value);
})

class Sudoku{
    constructor(){
        this.board =this.initilaizeBoard();
    }
    initilaizeBoard(){
        return Array(9).fill(null).map(()=>Array(9).fill(null));
    }
    printBoard(){
        console.group("Sudoku board");
        console.table(this.board);
        console.groupEnd();
    }

    resetBoard(){
        this.board = this.initilaizeBoard();
    }

    checkRow(row){
        let current_row = new Set();
        for(let i=0;i<9;i++){
            let current_num = this.board[row][i];
            if(current_num!=null&&current_row.has(current_num)){
                console.log(`Error occured in row ${row} and column ${i}`);
                return false;
            }
            current_row.add(current_num);
        }
        return true;
    }

    checkColumn(column){
        let current_column = new Set();
        for(let i=0;i<9;i++){
            let current_num = this.board[i][column];
            if(current_column!=null&&current_column.has(current_num)){
                console.log(`Error occured in column ${column} and row ${i}`);
                return false;
            }
            current_column.add(current_num);
        }
        return true;
    }

    checkBox(startRow,startColumn){

    }

    checkBoard(){
        for(let i=0;i<9;i++){
            if(!this.checkRow(i)) return false;
            if(!this.checkColumn(i)) return false;
        }
        return true;
    }
    
    addValue(row,column,value){
        // if(value<=0||value>9){
        //     throw new Error("Invalid value");
        // }
       this.board[row][column] = value;
    console.clear();
       this.printBoard();
    }
    
}

sud1 = new Sudoku();