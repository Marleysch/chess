'use client';

import {useState, useEffect} from 'react';

function Square ({color, piece, onSquareClick}){
  const imgPath = "/pieces/" + color + "/" + piece + ".png";
  return(
    <button className = "square-button"  onClick={onSquareClick}><img src={imgPath} className='chess-piece'/></button>
  )
}

function EmptySquare (){
  return (
    <button 
      className="square-button"
      onClick={()=>{}}
    >
      piece
    </button>
  )
}

export default function Board() {
  const [board, setBoard] = useState(null);

  useEffect(() => {
    fetch("http://localhost:18080/board")
    .then((response) => {
      if (!response.ok){
        throw new Error("Network Response not OK");
      }
      return response.json();
    })
    .then((data) => {
      console.log(data);
      setBoard(data);
    })
    .catch((error) => {
      console.error("Fetch Error", error);
    })
  }, []);

  return (
    <div className="board-container">
      <img src="/board.png" alt="Board" className="board-image" />
      <div className="board-grid">
        {board && board.map((row, rowIndex) => (
          row.map((square, squareIndex) => 
            square !== "Empty" ? (
              <Square
                key={`${rowIndex}-${squareIndex}`}
                color={square.split(" ")[0]}
                piece={square.split(" ")[1]}
                onSquareClick={() => console.log("clicked", rowIndex, squareIndex)}
              />
            ) : (
              <EmptySquare key={`${rowIndex}-${squareIndex}`} />
            )
          )
        ))}
      </div>
    </div>
  );
}


