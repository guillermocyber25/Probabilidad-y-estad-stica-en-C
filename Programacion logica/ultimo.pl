

ultimo([X|[]],X).
ultimo([_|J],X):-ultimo(J,X).
