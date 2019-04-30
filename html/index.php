<?php
?>
<!DOCTYPE html>
<html lang="fr">
<head>
<title>STS Versus</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" type="text/css" href="megacrit/style2.css">
<script src="https://code.jquery.com/jquery-3.1.1.js"></script>
<script type="text/javascript">
// $(document).ready(function(){

//     $("img").attr("object-fit","fill");

//     $("img").hover(
//         function(){
//             $(this).animate({width:"80px", height:"80px"},100);
//         },function(){
//             $(this).animate({width: "70px", height:"70px"},100);
//         }
//     );

// });
</script>
<style>
    /* Split the screen in half */
    .split {
    height: 100%;
    width: 50%;
    position: fixed;
    z-index: 1;
    top: 0;
    overflow-x: hidden;
    padding-top: 20px;
    }

    /* Control the left side */
    .left {
    left: 0;
    }

    /* Control the right side */
    .right {
    right: 0;
    }

    /* If you want the content centered horizontally and vertically */
    .centered {
    position: absolute;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    text-align: center;
    }

    .item{
        overflow: hidden;
        display: inline-block;
    }

    .item img {
        transition: transform .1s ease;
        object-fit: none;
        object-position: 50% 50%;
        width: 70px;
        height: 70px;
    }

    .item:hover img {
        transform: scale(1.2);
    }

    /* img{
    object-fit: none;
    object-position: 50% 50%;

    width: 70px;
    height: 70px;
    } */

    img:hover,a:hover{
        cursor:url(slay-the-spire.fandom/img/StScursor2.png),auto;
    }

    html{
        cursor:url(slay-the-spire.fandom/img/StScursor.png),auto;
    }
</style>
</head>
<body>
<div class="split left">
    <h1>Player1</h1>
    <div class="shadowblock" style="margin-left:10%;margin-right:10%">
        <div class="item">
            <img src="slay-the-spire.fandom/img/RedSkull.png" alt="Red Skull">
        </div>
        <div class="item">
            <img src="slay-the-spire.fandom/img/BurningBlood.png" alt="Burning Blood">
        </div>
    </div>
</div>

<div class="split right">
    <h1>Player2</h1>
    <div class="shadowblock" style="margin-left:10%;margin-right:10%">
    <center><a href="">lien</a></center>
    </div>
</div> 
</body>
</html>