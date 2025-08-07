'use client';

import Image from "next/image";

function Square ({x, y}){
  function handleClick(){
    console.log("button " + x + y + " been clicked");
  }
  return(
    <button className = "square-button" onClick={handleClick}>CLICK ME</button>
  )
}

export default function Home() {
  let board = Array(8).fill(null).map(() =>(Array(8).fill(null)));


  return (
    <div >
      {board.map((row, rowIndex) => {
        return (
          <div key={rowIndex}>
            {row.map((square, squareIndex) => {
              return (
                <Square y = {rowIndex}x = {squareIndex} key={squareIndex}/>
              )
            })}
          </div>
        )
      })}
    </div>
  );
}

