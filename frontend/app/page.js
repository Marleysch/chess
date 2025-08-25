'use client';

import {useState, useEffect} from 'react';

function Square ({color, piece, onSquareClick, highlighted}){
  const imgPath = "/pieces/" + color + "/" + piece + ".png";
  return(
    <button className = {highlighted}  onClick={onSquareClick}><img src={imgPath} className='chess-piece'/></button>
  )
}

function EmptySquare ({onEmptyClick}){
  return (
    <button 
      className="square-button"
      onClick={onEmptyClick}
    >
    </button>
  )
}

export default function Board() {
  const [board, setBoard] = useState(null);
  const [midMove, setMidMove] = useState(null);
  const [sourceRank, setSourceRank] = useState(null);
  const [sourceRow, setSourceRow] = useState(null);


  function handleClick( { rank, row }){
    if (midMove) {
      fetch(`http://localhost:18080/${sourceRank}/${sourceRow}/${rank}/${row}`)
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
      setMidMove(null);
      setSourceRank(null);
      setSourceRow(null);
    }
    else{
      setSourceRank(rank);
      setSourceRow(row);
      setMidMove(true);
      console.log(`${rank}, ${row}, ${midMove}`)
    }
    
  }

  function handleEmptyClick({rank,row}){
    if (midMove) {
      fetch(`http://localhost:18080/${sourceRank}/${sourceRow}/${rank}/${row}`)
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
      setMidMove(null);
      setSourceRank(null);
      setSourceRow(null);
    }
  }

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
    <div className='game-container'>
      <div className="board-container">
        <img src="/board.png" alt="Board" className="board-image" />
        <div className="board-grid">
          {board && board.map((row, rowIndex) => (
            row.map((square, squareIndex) => 
              square !== "Empty" ? (
                (() => {
                  if (rowIndex === sourceRow && squareIndex === sourceRank){
                    return (
                      <Square
                        key={`${rowIndex}-${squareIndex}`}
                        color={square.split(" ")[0]}
                        piece={square.split(" ")[1]}
                        onSquareClick={() => handleClick({rank: squareIndex, row: rowIndex})}
                        highlighted={'square-button-highlighted'}
                      />
                    );
                  }
                  else {
                    return (
                      <Square
                        key={`${rowIndex}-${squareIndex}`}
                        color={square.split(" ")[0]}
                        piece={square.split(" ")[1]}
                        onSquareClick={() => handleClick({rank: squareIndex, row: rowIndex})}
                        highlighted={'square-button'}
                      />
                    );
                  }
                })()
              ) : (
                <EmptySquare key={`${rowIndex}-${squareIndex}`} onEmptyClick={() => handleEmptyClick({rank:squareIndex, row: rowIndex})}/>
              )
            )
          ))}
        </div>
      </div>
      
    </div>
  );
}


