create table dectobin ( d integer primary key not null , b text not null );
create table dectohex ( d integer primary key not null , h text not null );

insert into dectobin ( d , b ) values
( 0  , '0000' ),
( 1  , '0001' ),
( 2  , '0010' ),
( 3  , '0011' ),
( 4  , '0100' ),
( 5  , '0101' ),
( 6  , '0110' ),
( 7  , '0111' ),
( 8  , '1000' ),
( 9  , '1001' ),
( 10 , '1010' ),
( 11 , '1011' ),
( 12 , '1100' ),
( 13 , '1101' ),
( 14 , '1110' ),
( 15 , '1111' );

insert into dectohex ( d, h ) values
( 0  , '0' ),
( 1  , '1' ),
( 2  , '2' ),
( 3  , '3' ),
( 4  , '4' ),
( 5  , '5' ),
( 6  , '6' ),
( 7  , '7' ),
( 8  , '8' ),
( 9  , '9' ),
( 10 , 'A' ),
( 11 , 'B' ),
( 12 , 'C' ),
( 13 , 'D' ),
( 14 , 'E' ),
( 15 , 'F' );

select * from dectobin natural join dectohex;