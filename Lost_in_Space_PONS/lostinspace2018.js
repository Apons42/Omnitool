"use strict"


/*************************************************************
Soucoupe
*************************************************************/


function Soucoupe(x,y) {
	this.x = x;
	this.y = y;
	this.vx = 4.5;
	this.vy = 4.5;
	this.running = true;
	this.unsafe = true;
	this.direction = "ArrowUp";
}
	
Soucoupe.prototype.Nom = "Soucoupe"

Soucoupe.prototype.toString = function() {
	return [this.Nom,"(",this.x.toFixed(2),", ", this.y.toFixed(2),")"].join('')
}

Soucoupe.prototype.dessine = function(direction) {
	/*Dessine la soucoupe. Si elle est détruite, affiche le message de fin de partie.*/
	let canvas = document.getElementById('game_area');
	let ship = canvas.getContext("2d");
	ship.clearRect(0, 0, canvas.width, canvas.height);
	
	if (this.running){
	
		if(this.x < 0) 
			this.x = 0;
		else if(this.x >= canvas.width ) 
			this.x = canvas.width  - 1
		if(this.y < 0) 
			this.y = 0;
		else if(this.y >= canvas.height) 
			this.y = canvas.height - 1;
		console.log(soucoupe.toString());
	
	
		ship.strokeStyle='#0000ff';
		ship.lineWidth= 3;
		ship.beginPath();
	
		if (direction == "ArrowUp"){
			ship.moveTo(this.x, this.y-5);
			ship.lineTo(this.x+5, this.y+5);
			ship.lineTo(this.x-5, this.y+5);
			ship.lineTo(this.x, this.y-5);}
		else if(direction == "ArrowDown"){
			ship.moveTo(this.x, this.y+5);
			ship.lineTo(this.x+5, this.y-5);
			ship.lineTo(this.x-5, this.y-5);
			ship.lineTo(this.x, this.y+5);}
		else if(direction == "ArrowLeft"){
			ship.moveTo(this.x-5, this.y);
			ship.lineTo(this.x+5, this.y+5);
			ship.lineTo(this.x+5, this.y-5);
			ship.lineTo(this.x-5, this.y)}
		else if(direction == "ArrowRight"){
			ship.moveTo(this.x+5, this.y);
			ship.lineTo(this.x-5, this.y+5);
			ship.lineTo(this.x-5, this.y-5);
			ship.lineTo(this.x+5, this.y)}
	}
	else{
		soucoupe.explose();
	}
	ship.stroke();
}

Soucoupe.prototype.explose = function() {
	/*Détruit la soucoupe et affiche un message de fin de partie.*/
	let canvas = document.getElementById('game_area');
	let boom = canvas.getContext('2d');
	boom.fillStyle = '#dddddd';
	boom.font = "20px Arial";
	boom.fillText('Les extraterrestres ont eu raison de vous...', 115, 20)
	this.running = false
}


Soucoupe.prototype.shoot = function(direction, tirs) {
	/*Tire un missile.*/
	let info;
	if (this.running && this.unsafe){
	if (direction == "ArrowUp"){
	info = {sx:this.x, sy:this.y-6, vsx:0, vsy:this.vy*-1, travelTime:canvas.width/2, side:direction};}
	else if (direction == "ArrowDown"){
	info = {sx:this.x, sy:this.y+6, vsx:0, vsy:this.vy, travelTime:canvas.width/2, side:direction};}
	else if (direction == "ArrowLeft"){
	info = {sx:this.x-6, sy:this.y, vsx:this.vx*-1, vsy:0, travelTime:canvas.width/2, side:direction};}
	else if (direction == "ArrowRight"){
	info = {sx:this.x+6, sy:this.y, vsx:this.vx, vsy:0, travelTime:canvas.width/2, side:direction};}
	tirs.push(info)}}
	




/************************************************************
Tirs de la soucoupe
*************************************************************/
let tirs = []
let seeShots = function(tirs) {
	/*Affiche tous les missiles tirés.*/
	let canvas = document.getElementById('game_area');
	let shot = canvas.getContext("2d");
	shot.strokeStyle = '#59c4ff';
	shot.lineWidth = 3;
	shot.beginPath();
	
	tirs.forEach(function(info){
	if (info.side == "ArrowUp"){
		shot.moveTo(info.sx, info.sy+2);
		shot.lineTo(info.sx, info.sy-3);
	}
	else if (info.side == "ArrowDown"){
		shot.moveTo(info.sx, info.sy-2);
		shot.lineTo(info.sx, info.sy+3);
	}	
	else if (info.side   == "ArrowLeft"){
		shot.moveTo(info.sx+2, info.sy);
		shot.lineTo(info.sx-3, info.sy);
	}	
	else if (info.side == "ArrowRight"){
		shot.moveTo(info.sx+2, info.sy);
		shot.lineTo(info.sx-3, info.sy);
	}	
	shot.stroke();
	});
}

let clearShots = function(tirs){
	/* Ralentit les missiles et retire qui sont allés trop loin ou sont entrés en collision avec une entité.*/
	tirs.forEach(function(info){
	if (info.side == "ArrowUp"){
		info.travelTime += info.vsy}
	else if (info.side == "ArrowDown"){
		info.travelTime -= info.vsy}
	else if (info.side   == "ArrowLeft"){
		info.travelTime += info.vsx;}
	else if (info.side == "ArrowRight"){
		info.travelTime -= info.vsx}
	
		info.sx += info.vsx;
		info.sy += info.vsy;
		info.vsx *= 0.99
		info.vsy *= 0.99
	})
	let newTirs = tirs.filter(function (tir){
		return tir.travelTime > 0;
	});
	return newTirs;
}



/************************************************************
Vaisseaux
*************************************************************/

function Vaisseau(x,y){
	this.x = x
	this.y = y
	this.vx = 1.2
	this.vy = 0.8
	this.alive = true
}


let armee = [];
let armada = function(legion, armee){
	/*Si les ennemis en jeu ne sont pas assez nombreux, essaye de rajouter un vaisseau.*/
	let neg;
	let renfort;
	let canvas = document.getElementById('game_area');
	if (armee.length < 50 && legion !=0){
		neg = Math.random()*2;
		if (neg < 1){
			renfort = new Vaisseau(0, Math.random()*canvas.height/2);
		}
		else {
			renfort = new Vaisseau(canvas.width, Math.random()*canvas.height/2);
		}
	armee.push(renfort);
	return legion-1
	}
	return legion
}

let affichage = function(armee) {
	/*Affiche tous les vaisseaux et augmente leur vitesse si nécessaire.*/
	let canvas = document.getElementById('game_area')
	let vessel = canvas.getContext('2d');
	vessel.strokeStyle = '#207020';
	vessel.lineWidth = 3;
	vessel.lineCap = "round"
	vessel.lineJoin = "round"
	vessel.beginPath();
	
	armee.forEach(function(soldat){
	if(soldat.x < 0 || soldat.x >= canvas.width) 
		soldat.vx *= -1;
	if(soldat.y < 0 || soldat.y >= canvas.height) {
		soldat.vy *= -1.1;
		soldat.vx *= 1.05;
	}
	
	
	vessel.moveTo(soldat.x, soldat.y-5);
	vessel.lineTo(soldat.x-5  , soldat.y);
	vessel.lineTo(soldat.x, soldat.y+5);
	vessel.lineTo(soldat.x+5, soldat.y);
	vessel.lineTo(soldat.x, soldat.y-5);
	soldat.x += soldat.vx;
	soldat.y += soldat.vy;
	})
	vessel.stroke();
}

/************************************************************
Interactions entre chaque entité
*************************************************************/


let dessineTout = function(soucoupe, tirs){
	/*Fonction regroupant les fonctions d'affichage*/
	soucoupe.dessine(soucoupe.direction);
	seeShots(tirs);
	affichage(armee);
};


let collision = function(soucoupe, tirs, armee){
	/*Détecte les collisions entre chaque entité différente.*/
	armee.forEach(function(soldat){
		if (soldat.x >= soucoupe.x-5 && soldat.x <= soucoupe.x+5 && soldat.y >= soucoupe.y-5 && soldat.y <= soucoupe.y+5){
				soucoupe.explose();}
	})
	
	tirs.forEach(function(tir){
	if (tir.sx >= soucoupe.x-5 && tir.sx <= soucoupe.x+5 && tir.sy >= soucoupe.y-5 && tir.sy <= soucoupe.y+5){
		soucoupe.explose();
		tir.travelTime = 0;
	}
	else {
		armee.forEach(function(soldat){
			if (tir.sx >= soldat.x-5 && tir.sx <= soldat.x+5 && tir.sy >= soldat.y-5 && tir.sy <= soldat.y+5){
				soldat.alive = false;
				tir.travelTime = 0;}
			})};})  
	let newArmee = armee.filter(function(survivant){
		return survivant.alive})
	return newArmee	
}

let issueBataille = function(meute, phalange, soucoupe){
	/*Affiche le nombre d'ennemis dans la zone ainsi que les renforts restants. Si il n'y a plus aucun ennemi, affiche aussi le message de victoire*/
	let canvas = document.getElementById('game_area');
	let triomphe = canvas.getContext('2d')
	triomphe.font = "20px Arial";
	triomphe.fillStyle = '#dddddd';
	if (meute + phalange.length == 0){
		triomphe.fillText("Vous avez repoussé vos attaquants !", 140, 20);
		soucoupe.unsafe = false;
	}
	triomphe.font = "10px Arial";
	triomphe.fillText("Renforts ennemis restants : " + meute, 9, canvas.height-10)
	triomphe.fillText("Ennemis dans la zone : " + phalange.length, 9, canvas.height-30)
}

/*********************************************
Gestionnaire d'événements
*********************************************/	
let canvas;
let soucoupe;
let vaisseau;

function action(e) {
	let m;
	console.log(e.code)
	e.preventDefault()
	switch(e.code) {
	case "KeyW":
		soucoupe.y -= soucoupe.vy;
		soucoupe.direction = "ArrowUp";
		break;
	case "KeyS":
		soucoupe.y += soucoupe.vy;
		soucoupe.direction = "ArrowDown";
		break
	case "KeyA":
		soucoupe.x -= soucoupe.vx;
		soucoupe.direction = "ArrowLeft";
		break
	case "KeyD":
		soucoupe.x += soucoupe.vx;
		soucoupe.direction = "ArrowRight";
		break
	case "Space":
		soucoupe.shoot(soucoupe.direction, tirs);
		breakz
	case "KeyO":
		soucoupe.explose();
		break
	case "KeyH":
	case "KeyQ":
		afficheAide()
		break
	case "KeyP":
	case "NumpadAdd":
		soucoupe.vx *= 1.2 
		soucoupe.vy *= 1.2
		break
	case "Semicolon":
	case "NumpadSubtract":
		if(soucoupe.vx > 1) soucoupe.vx /= 1.2
		if(soucoupe.vy > 1) soucoupe.vy /= 1.2
		break
	}
	
;
}	
	
function afficheAide() {
	alert(Aide.join('\n'))
}

  
let Aide = [
"Vous détenez des informations cruciale pour la survie de l'espèce humaine,",
"mais une flotte entière de vaisseaux extraterrestres vous poursuit !",
"",
"Votre objectif : survivre et éliminer les 300 vaisseaux lancés pour vous arrêter.",
"",
"",
"Contrôles :",
"",
"-'Z', 'Q', 'S', 'D' pour se déplacer",
"-'+' du pavé numérique ou 'P' pour augmenter la vitesse de la soucoupe.",
"-'-' du pavé numérique ou 'M' pour diminuer la vitesse de la soucoupe.",
"-'Espace' pour tirer un missile avec une vitesse égale,",
" à celle de la soucoupe",
"-'H' ou 'A' pour afficher cette aide et mettre le jeu en pause.",
"-'O' pour faire exploser la soucoupe. L'humain à bord n'a pas eu le temps",
" de désactiver le système d'autodestruction. A n'utiliser que si il le faut, donc.",
"",
"",
"Notes :",
"",
"-Ni la soucoupe ni les vaisseaux ne peuvent sortir de la fenêtre de jeu.",
"-Un maximum de 50 vaisseaux peuvent être présents en même temps sur l'écran.",
"-Ces vaisseaux accélèrent à chaque rebond en haut et en bas de la zone de jeu",
"-Un missile disparait si :",
"	-Il entre en collision avec tout ce qui n'est pas un autre missile,",
"	 le détruisant au passage (soucoupe incluse) ;",
"	-Il parcourt une distance égale à la moitié de la hauteur de la zone de jeu.",
"-Attention : les missiles peuvent finir par rester immobiles si la soucoupe",
" est trop lente (ils restent cependant mortels).",
"",
"",
"Bon jeu à vous, et bonne chance !",
]
   




window.onload = function() {
	let flotte = 300;
	canvas = document.getElementById('game_area');
	canvas.parentNode.onkeypress = action;
	soucoupe = new Soucoupe(canvas.width/2, canvas.height - 50);
	soucoupe.dessine(soucoupe.direction);
	console.log("init " + soucoupe);
	afficheAide();
	setInterval(function(){
		dessineTout(soucoupe, tirs);
		tirs=clearShots(tirs);
		armee = collision(soucoupe, tirs, armee)
		issueBataille(flotte, armee, soucoupe)}, 31); /* Valeur de base : 31 */
	setInterval(function(){
		flotte = armada(flotte, armee);}, 500)
}
