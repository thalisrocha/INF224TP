import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class UI extends JFrame {

    private static final long serialVersionUID = 1L;

    private JButton button1;
    private JButton button2;
    private JButton button3;
    private JPanel buttonPanel;
    private JTextArea requestArea;
    private JTextArea responseArea;
    private JMenuBar menuBar;
    private Client client;

    public static void main(String argv[]){
        new UI(null);
    }

    public UI(Client client){
        super();
        this.client = client;

        
        responseArea = new JTextArea();
        add(new JScrollPane(responseArea));
        add(responseArea,BorderLayout.CENTER);

        button1 = new JButton("Display an object");
        button1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                String request = (String)JOptionPane.showInputDialog(
                    UI.this,
                    "Type the name of the object to request",
                    JOptionPane.PLAIN_MESSAGE);
                String ans = UI.this.client.send("DisplayObject " + request);
                ans = ans.replace("|","\n");
                responseArea.append(ans+"\n");
                } 
        });
        button2 = new JButton("Play an object");
        button2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                String request = (String)JOptionPane.showInputDialog(
                    UI.this,
                    "Type the name of the object to play",
                    JOptionPane.PLAIN_MESSAGE);
                System.out.println(request);
                String ans = UI.this.client.send("Play " + request);
                ans = ans.replace("|","\n");
                responseArea.append(ans+"\n");
                } 
        });
        button3 = new JButton("Quitter");
        button3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                System.exit(0);
                } 
        });
        buttonPanel = new JPanel();
        buttonPanel.add(button1, BorderLayout.WEST);
        buttonPanel.add(button2, BorderLayout.CENTER);
        buttonPanel.add(button3, BorderLayout.EAST);
        add(buttonPanel, BorderLayout.SOUTH);

        menuBar = new JMenuBar();
        JMenu menu = new JMenu("Menu");
        JToolBar toolBar = new JToolBar();
        JMenuItem menu1 = new JMenuItem("Bouton 1");
        menu1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                responseArea.append("Bouton 1");
                } 
        });
        JMenuItem menu2 = new JMenuItem("Bouton 2");
        menu2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                responseArea.append("Bouton 1");
                } 
        });
        JMenuItem menu3 = new JMenuItem("Quitter");
        menu3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                System.exit(0);
                } 
        });
        menu.add(menu1);
        menu.add(menu2);
        menu.add(menu3);
        JMenuItem menu1bis = new JMenuItem("Bouton 1");
        menu1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                responseArea.append("Bouton 1");
                } 
        });
        JMenuItem menu2bis = new JMenuItem("Bouton 2");
        menu2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                responseArea.append("Bouton 1");
                } 
        });
        JMenuItem menu3bis = new JMenuItem("Quitter");
        menu3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent event ) {
                System.exit(0);
                } 
        });
        toolBar.add(menu1bis);
        toolBar.add(menu2bis);
        toolBar.add(menu3bis);
        
        menuBar.add(menu);
        menuBar.add(toolBar);

        setJMenuBar(menuBar);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Télécommande");
        pack();
        setSize(946,530);
        setVisible(true);
    }

}