import {Component, Injectable, OnInit, ViewEncapsulation} from '@angular/core';
import {ActivatedRouteSnapshot, CanDeactivate, Router, RouterStateSnapshot} from "@angular/router";
import {Observable} from "rxjs/Observable";

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
  encapsulation: ViewEncapsulation.None
})
export class AppComponent {
  public pageTitle: string = 'The Wisdom Whisperer';
  public landingIntro: string = 'welcome to my journey';

  constructor(protected router: Router) {
  }


}
