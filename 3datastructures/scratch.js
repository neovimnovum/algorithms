const myarray = [3, 4, 2, 8, 1, 4, -34, -10, -9, -8];
const mins = [];

let min = myarray[0];

myarray.forEach((num) => {
  if (num < min) {
    min = num;
  }
  mins.push(min);
});

const stack = [];

bool = false;

[-8,-9,-10,]

for (let j = myarray.length - 1; j >= 0; j -= 1) {
  if (myarray[j] > mins[j]) {
    while(stack.at(-1) < mins[j]) {
      stack.pop();
    }
    if (stack.at(-1) < myarray[j]) {
      bool = true;
    } 
    stack.push(myarray[j]);
  }
}
