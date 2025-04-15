import * as THREE from 'three';

const scene = new THREE.Scene();
const camera = new THREE.OrthographicCamera(0, 800, 0, 600, -1000, 1000);

const renderer = new THREE.WebGLRenderer();

renderer.setClearColor( 0xffffff );
renderer.setSize( window.innerWidth, window.innerHeight );
renderer.setAnimationLoop( animate );
document.body.appendChild( renderer.domElement );

const lineMaterial = new THREE.LineBasicMaterial( {
  color: 0x000000,
  linewidth: 3 });
const points = [];

function drawLine(x0, y0, x1, y1) {
  points.push( new THREE.Vector3( x0, y0, 0 ) );
  points.push( new THREE.Vector3( x1, y1, 0 ) );
}

const lineGeometry = new THREE.BufferGeometry().setFromPoints( points );
const line = new THREE.Line( lineGeometry, lineMaterial );
scene.add( line );



function animate() {

  renderer.render( scene, camera );

}

window.drawLine = function (x0, y0, x1, y1) {
  console.log("window.drawLine" + x0 + " " + y0 + " " + x1 + " " + y1);
  const pts = [];
  pts.push( new THREE.Vector3( x0, y0, 0 ) );
  pts.push( new THREE.Vector3( x1, y1, 0 ) );
  const lineGeo = new THREE.BufferGeometry().setFromPoints(pts);
  const dline = new THREE.Line( lineGeo, lineMaterial);
  scene.add(dline);
}

export { drawLine };
