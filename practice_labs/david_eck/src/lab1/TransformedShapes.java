package lab1;

import java.awt.*;
import javax.swing.*;
import java.awt.geom.AffineTransform;


public class TransformedShapes extends JPanel {

	//------- For drawing ONLY while paintComponent is being executed! --------

	private Graphics2D g2; // A copy of the graphics context from paintComponent.

	/**
	 * Removes any transformations that have been applied to g2, so that
	 * it is back to the standard default coordinate system.
	 */
	private void resetTransform() {
		g2.setTransform(new AffineTransform());
	}

	/**
	 * Draws a filled circle of radius 50 (diameter 100) centered at (0,0), 
	 * subject to whatever transform(s) have been applied to g2.
	 */
	private void circle() {
		g2.fillOval(-50,-50,100,100);
	}

	/**
	 * Draws a filled square with side 100 centered at (0,0), subject
	 * to whatever transform(s) have been applied to g2.
	 */
	private void square() {
		g2.fillRect(-50,-50,100,100);
	}

	/**
	 * Draws a filled triangle with vertices at (-50,50), (50,50), and 
	 * (0,-50), subject to whatever transform(s) have been applied to g2.
	 */
	private void triangle() {
		g2.fillPolygon(new int[] {-50,50,0}, new int[] {50,50,-50}, 3);
	}

	//-----------------------------------------------------------------------------------


	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		g2 = (Graphics2D)g.create();
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

		// TODO Draw the required image, using ONLY the four methods defined above, 
		// along with g2.setColor, g1.scale, g2.translate, and g2.rotate.

		/* ----------------------------------------------------------------------- */

		/*
		Yellow square, black circle
		 */
		g2.translate(150, 150);

		//Draw black circle first (in the background)
		g2.scale(2.0, 2.0);
		g2.setColor(Color.black);
		circle();

		//Yellow square
		g2.scale(0.5, 0.5);
		g2.setColor(Color.yellow);
		square();

		resetTransform();

		/*
		Green square with white pyramid
		*/
		g2.translate(450, 150);

		//Square
		g2.scale(2.0, 2.0);
		g2.setColor(Color.green);
		square();

		//Scale y to be half of square height
		g2.scale(1.0, 0.5);

		//White triangle
		g2.translate(0.0, 50);
		g2.setColor(Color.white);
		triangle();

		resetTransform();

		/*
		Blue hourglass-lookin' thing
		 */
		g2.translate(150, 450);

		//Blue rectangle
		g2.scale(1.5, 0.75);
		g2.setColor(Color.blue);
		square();

		//Reset scale
		g2.scale(1/1.5, 1/0.75);

		//Set triangle size to be 0.75 original
		g2.scale(0.75, 0.75);

		//Bottom triangle
		g2.translate(0.0, 100.0);
		triangle();

		//Flip the triangle and draw above the rectangle
		g2.translate(0.0, -200.0);
		g2.scale(1.0, -1.0);
		triangle();

		resetTransform();

		/*
		Red Z
 		*/
		g2.translate(450, 450);

		//Diagonal line
		g2.rotate(-Math.PI / 4);
		g2.scale(3.0, 0.1);
		g2.setColor(Color.red);
		square();
		//Reset
		g2.scale(1/3.0, 1/0.1);
		g2.rotate(Math.PI / 4);

		//Top line
		g2.translate(0, -110);
		g2.scale(2.1, 0.1);
		square();
		//Reset
		g2.scale(1/2.1, 1/0.1);

		//Bottom line
		g2.translate(0, 220);
		g2.scale(2.1, 0.1);
		square();
		
		/* ----------------------------------------------------------------------- */
		
	} // end paintComponent()


	//--------------------------------------------------------------------------------------

	public TransformedShapes() {
		setPreferredSize(new Dimension(600,600) );
		setBackground(Color.WHITE);
		setBorder(BorderFactory.createLineBorder(Color.BLACK,4));
	}

	public static void main(String[] args)  {
		JFrame window = new JFrame("Drawing With Transforms");
		window.setContentPane(new TransformedShapes());
		window.pack();
		window.setResizable(false);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		window.setLocation( (screen.width - window.getWidth())/2, (screen.height - window.getHeight())/2 );
		window.setVisible(true);
	}

}
