
var submit_button = document.getElementById('submit-button');
var form_row = document.getElementById('row');
var form_col = document.getElementById('col');
var form_val = document.getElementById('val');
let wipe_button = document.getElementById('wipe');
submit_button.addEventListener('click',()=>{
    sud1.addValue(form_row.value-1,form_col.value-1,form_val.value);
})

var generate_button = document.getElementById('generate-button');
generate_button.addEventListener('click',()=>{
    sud1.generateValidBoard();
    alert('The valid board was generated');
});
wipe_button.addEventListener('click',()=>{
    sud1.wipeBoard();
    sud1.printBoard();
    alert("The thole field was wiped");
})


class Sudoku{
    constructor(){
        this.board = Array(9).fill(null).map(()=>Array(9).fill(null));
    }

    wipeBoard(){
        this.board = Array(9).fill(null).map(()=>Array(9).fill(null));
    }
    
    checkRow(row){
        let current_row = new Set();
        for(let i=0;i<9;i++){
            if(this.board[row][i]!=null&&current_row.has(this.board[row][i])){
                alert(`Fail in column ${i}, row ${row}\n Read the rules and try again`);
                console.clear();
                //this.wipeBoard();
            }
            current_row.add(this.board[row][i]);
        }
       
    }

    checkColumn(column){
        let current_column = new Set();
        for(let i=0;i<9;i++){
            if(this.board[i][column]!=null&&current_column.has(this.board[i][column])){
                alert(`Fail in column ${column}, row ${i}\n Read the rules and try again`);
                console.clear();
                //this.wipeBoard();
            }
            current_column.add(this.board[i][column]);
        }
       
    }

    checkBoard(){
        for(let i=0;i<9;i++){
            this.checkRow(i);
            this.checkColumn(i);
        }
        return true;
    }

    isValidBox(rowIndex, colIndex) {
        let seen = new Set();
        let startRow = Math.floor(rowIndex / 3) * 3;
        let startCol = Math.floor(colIndex / 3) * 3;
        for (let i = 0; i < 3; i++) {
          for (let j = 0; j < 3; j++) {
            let num = this.board[startRow + i][startCol + j];
            if (num !== 0 && seen.has(num)) {
              alert(`Fail in box (${Math.floor(rowIndex / 3) + 1},${Math.floor(colIndex / 3) + 1})\n Read the rules and try again`);
              console.clear();
              //this.wipeBoard();
              return false;
            }
            seen.add(num);
          }
        }
        return true;
      }

    printBoard(){
        console.clear();
        console.group("Sudoku board");
        console.table(this.board);
        console.groupEnd();
    }

    addValue(row, column,value){
        this.board[row][column] = value;
        this.checkBoard();
        this.printBoard();
    }

    generateValidBoard() {
        

        this.wipeBoard();

        let num = 0;
        let start = 0;
        let flag1 = false;
        let flag2 = false;
        for (let i = 0; i < 9; i++) {
            for(let j = 0; j < 9; j++){
                //this.board[i][j] = ++num;
                this.addValue(i,j,++num);
                if(num === 9){
                    num = 0;
                }
            }
            num = start + ((i + 1) % 3) * 3;
            if (i === 2 && !flag1){
                num = 1;
                start = 1;
                flag1 = true;
            }
            if(i === 5 && !flag2){
                num = 2;
                start = 2;
                flag2 = true;
            }
        }
    }
    
}

sud1 = new Sudoku();
sud1.printBoard();